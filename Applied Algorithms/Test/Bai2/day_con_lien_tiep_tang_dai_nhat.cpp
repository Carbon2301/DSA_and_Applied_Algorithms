#include <bits/stdc++.h>
using namespace std;

int longest(vector<int>& arr) {
    int maxLen = 1, currentLen = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        } else {
            currentLen = 1;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 5, 1, 6, 7, 8};
    cout << longest(arr) << endl;
    return 0;
}
