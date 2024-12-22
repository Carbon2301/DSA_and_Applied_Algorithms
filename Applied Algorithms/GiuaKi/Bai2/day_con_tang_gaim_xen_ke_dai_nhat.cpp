#include <bits/stdc++.h>
using namespace std;

int longestAlternatingSubarray(vector<int>& arr) {
    if (arr.size() < 2) return arr.size();

    int maxLength = 1, currentLength = 1;

    for (int i = 1; i < arr.size(); i++) {
        if ((arr[i] > arr[i-1] && i % 2 == 1) || (arr[i] < arr[i-1] && i % 2 == 0)) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 2; // Bắt đầu lại
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {6, 3, 2, 4, 3, 5, 4, 4};
    cout << "Length of longest alternating subarray: "
         << longestAlternatingSubarray(arr) << endl;
    return 0;
}
