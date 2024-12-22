#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 1};
    int k = 2;
    map<int, int> prefix_sum;
    int sum = 0, count = 0;

    prefix_sum[0] = 1;

    for (int x : arr) {
        sum += x;
        if (prefix_sum.find(sum - k) != prefix_sum.end()) {
            count += prefix_sum[sum - k];
        }
        prefix_sum[sum]++;
    }

    cout << count << endl;
    return 0;
}
