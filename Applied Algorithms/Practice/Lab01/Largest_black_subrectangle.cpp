#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<vector<int> > a(1000, vector<int>(1000, 0)); // S?a d?u >>
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int> > height(n, vector<int>(m, 0)); // S?a d?u >>
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
            }
        }
    }

    int max_area = 0;
    for (int i = 0; i < n; i++) {
        stack<int> s;
        int j = 0;
        while (j < m) {
            if (s.empty() || height[i][s.top()] <= height[i][j]) {
                s.push(j++);
            } else {
                int tp = s.top();
                s.pop();
                int area = height[i][tp] * (s.empty() ? j : j - s.top() - 1);
                max_area = max(max_area, area);
            }
        }
        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            int area = height[i][tp] * (s.empty() ? j : j - s.top() - 1);
            max_area = max(max_area, area);
        }
    }

    cout << max_area << endl;
    return 0;
}

