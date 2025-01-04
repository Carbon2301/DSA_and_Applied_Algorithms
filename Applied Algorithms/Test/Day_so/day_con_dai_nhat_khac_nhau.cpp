#include <bits/stdc++.h>
using namespace std;

int longUnique(vector<int>& arr) {
    unordered_set<int> seen;
    int start = 0, maxLen = 0;
    for (int end = 0; end < arr.size(); end++) {
        while (seen.count(arr[end])) {
            seen.erase(arr[start]);
            start++;
        }
        seen.insert(arr[end]);
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 7, 3, 1, 4, 5, 2, 6};
    cout << longUnique(arr) << endl;
    return 0;
}
