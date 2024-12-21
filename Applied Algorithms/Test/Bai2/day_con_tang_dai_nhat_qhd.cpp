#include <bits/stdc++.h>
using namespace std;

int longest(vector<int>& arr) {
    vector<int> lis;

    for (int x : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    return lis.size();
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << longest(arr) << endl;
    return 0;
}
