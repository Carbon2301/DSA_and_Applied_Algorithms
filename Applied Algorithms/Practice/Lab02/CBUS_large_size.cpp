#include <bits/stdc++.h>

using namespace std;

struct Request {
    int pickup;
    int dropoff;
};

int main() {
    int n, k;
    cin >> n >> k;
    int size = 2 * n + 1;
    vector<vector<int>> c(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> c[i][j];
        }
    }

    vector<Request> requests(n);
    for (int i = 0; i < n; ++i) {
        requests[i] = {i + 1, i + n + 1};
    }

    vector<int> route;
    vector<bool> picked(n, false), delivered(n, false);
    int current = 0;
    int capacity = 0;

    while (route.size() < 2 * n) {
        int next = -1;
        int minDist = INT_MAX;


        for (int i = 0; i < n; ++i) {
            if (!picked[i] && capacity < k) {
                int dist = c[current][requests[i].pickup];
                if (dist < minDist) {
                    minDist = dist;
                    next = requests[i].pickup;
                }
            }
        }


        for (int i = 0; i < n; ++i) {
            if (picked[i] && !delivered[i]) {
                int dist = c[current][requests[i].dropoff];
                if (dist < minDist) {
                    minDist = dist;
                    next = requests[i].dropoff;
                }
            }
        }

        if (next == -1) break;

        route.push_back(next);
        // Update status
        for (int i = 0; i < n; ++i) {
            if (next == requests[i].pickup) {
                picked[i] = true;
                capacity++;
            }
            if (next == requests[i].dropoff) {
                delivered[i] = true;
                capacity--;
            }
        }
        current = next;
    }



    cout << n << endl;
    for (int point : route) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
