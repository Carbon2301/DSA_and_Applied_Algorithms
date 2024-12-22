#include <bits/stdc++.h>
using namespace std;

int longSum(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSum = {{0, -1}}; // Tổng 0 tại vị trí -1
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (prefixSum.count(sum - k))
            maxLen = max(maxLen, i - prefixSum[sum - k]);
        if (!prefixSum.count(sum))
            prefixSum[sum] = i; // Chỉ lưu vị trí đầu tiên của tổng
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, -2, 5, -1, 4};
    int k = 5;
    cout << longSum(arr, k) << endl;
    return 0;
}
