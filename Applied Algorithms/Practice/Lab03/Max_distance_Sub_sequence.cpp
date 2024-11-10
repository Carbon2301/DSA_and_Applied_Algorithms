#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& positions, int C, int minDist) {
    int count = 1;
    int lastPosition = positions[0];
    
    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPosition >= minDist) {
            ++count;
            lastPosition = positions[i];
            if (count == C) return true;
        }
    }
    return false;
}

int findMaxMinDistance(vector<int>& positions, int C) {
    sort(positions.begin(), positions.end());
    int left = 1, right = positions.back() - positions.front(), result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceCows(positions, C, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        vector<int> positions(N);
        for (int i = 0; i < N; ++i) {
            cin >> positions[i];
        }
        cout << findMaxMinDistance(positions, C) << endl;
    }
    return 0;
}
