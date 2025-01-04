#include <bits/stdc++.h>
using namespace std;

int longest(vector<int>& arr) {
    unordered_map<int, int> prefix = {{0, -1}};
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += (arr[i] % 2 == 0) ? 1 : -1; // +1 cho số chẵn, -1 cho số lẻ
        if (prefix.count(sum))
            maxLen = max(maxLen, i - prefix[sum]);
        else
            prefix[sum] = i;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {2, 1, 6, 1, 3, 1, 1, 4, 3, 1};
    cout << longest(arr) << endl;
    return 0;
}
