#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int m, n;  // Number of teachers and courses
vector<vector<int> > preferences;  // Preferences: which courses each teacher can teach
vector<vector<bool> > conflicts;   // Conflict matrix: which courses cannot be assigned to the same teacher
vector<int> courseAssignment;     // Stores the teacher assigned to each course
vector<int> teacherLoad;          // Stores the number of courses assigned to each teacher
int bestMaxLoad = INT_MAX;        // The minimum of the maximum loads found
vector<int> bestAssignment;       // Stores the optimal assignment of courses

// Function to check if a given assignment is valid
bool isValidAssignment(int course, int teacher) {
    // Check if teacher can teach this course
    if (find(preferences[teacher].begin(), preferences[teacher].end(), course) == preferences[teacher].end()) {
        return false;
    }

    // Check if this teacher already has a conflicting course
    for (int i = 0; i < n; i++) {
        if (courseAssignment[i] == teacher && conflicts[course][i]) {
            return false;
        }
    }

    return true;
}

// Optimized backtracking function with pruning
void assignCourses(int courseIndex) {
    if (courseIndex == n) {
        // If all courses are assigned, calculate the current maximal load
        int currentMaxLoad = *max_element(teacherLoad.begin(), teacherLoad.end());
        if (currentMaxLoad < bestMaxLoad) {
            bestMaxLoad = currentMaxLoad;
            bestAssignment = courseAssignment; // Store the best assignment
        }
        return;
    }

    // Try assigning each course to a teacher, with pruning on teacher load
    for (int teacher = 0; teacher < m; teacher++) {
        // Skip assignments if the load exceeds the current best max load
        if (teacherLoad[teacher] >= bestMaxLoad) {
            continue;
        }

        if (isValidAssignment(courseIndex, teacher)) {
            // Assign the course to the teacher
            courseAssignment[courseIndex] = teacher;
            teacherLoad[teacher]++;
            
            // Recursively assign the next course
            assignCourses(courseIndex + 1);
            
            // Backtrack: unassign the course
            teacherLoad[teacher]--;
            courseAssignment[courseIndex] = -1;
        }
    }
}

int main() {
    // Read the number of teachers and courses
    cin >> m >> n;
    
    // Initialize preferences and conflicts
    preferences.resize(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        preferences[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> preferences[i][j];
            preferences[i][j]--;  // Make courses zero-indexed
        }
    }

    int k;
    cin >> k;
    conflicts.resize(n, vector<bool>(n, false)); // n x n matrix to track conflicts
    for (int i = 0; i < k; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        c1--; c2--;  // Make courses zero-indexed
        conflicts[c1][c2] = true;
        conflicts[c2][c1] = true; // Since it's a bidirectional conflict
    }

    // Initialize variables
    courseAssignment.resize(n, -1);  // -1 means no teacher assigned yet
    teacherLoad.resize(m, 0);        // No teacher has any courses initially

    // Start backtracking from course 0
    assignCourses(0);

    // Output the best assignment
    if (bestMaxLoad == INT_MAX) {
        cout << -1 << endl;  // No solution found
    } else {
        cout << n << endl;  // Output the number of courses
        for (int i = 0; i < n; i++) {
            cout << bestAssignment[i] + 1 << " ";  // Convert to 1-based index
        }
        cout << endl;
    }

    return 0;
}

