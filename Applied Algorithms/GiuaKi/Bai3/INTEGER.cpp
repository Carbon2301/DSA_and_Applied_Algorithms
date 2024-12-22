#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int n, M;
int a[MAX];
int t[MAX];
int X[MAX];
int f;
int Count;

void initT() {
    t[1] = a[1];
    int i;
    for (i = 2; i <= n; i++)
        t[i] = t[i-1] + a[i];
}

void TRY(int k) {
    int v;
    for (v = 1; v <= (M - f - (t[n] - t[k])) / a[k]; v++) {
        X[k] = v;
        f += a[k] * X[k];
        if (k == n) {
            if (f == M) Count++;
        } else {
            TRY(k + 1);
        }
        f -= a[k] * X[k];
    }
}

void solve() {
    f = 0;
    initT();
    TRY(1);
    cout << Count;
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
    return 0;
}
