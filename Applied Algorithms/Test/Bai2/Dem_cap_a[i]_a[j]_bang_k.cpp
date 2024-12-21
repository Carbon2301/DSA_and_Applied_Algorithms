#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    map<int, int> seen;
    int Q = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (seen[M - a[i]]) {
            Q++;
        }
        seen[a[i]]++;
    }
    cout << Q << endl;
    return 0;
}
