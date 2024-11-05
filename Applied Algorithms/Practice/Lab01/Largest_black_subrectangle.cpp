#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e3 + 1;
int a[N][N];
int n, m;
int h[N];
int L[N], R[N];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

long long compute() {
    vector<int> V;
    // Tính toán biên ph?i R
    for(int i = 1; i <= m; i++) {
        while(!V.empty() && h[i] < h[V.back()]) {
            R[V.back()] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    // Lam sach stack cho bien trai
    V.clear();
    // Tinh toan bien trai L
    for(int i = m; i >= 1; i--) {
        while(!V.empty() && h[i] < h[V.back()]) {
            L[V.back()] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    // Tinh dien tich hinh chu nhat lon nhat
    long long max_area = 0;
    for(int i = 1; i <= m; i++) {
        long long area = (R[i] - L[i] - 1) * h[i];
        max_area = max(max_area, area);
    }
    return max_area;
}

void solve() {
    long long ans = 0;
    fill(h, h + m + 1, 0); // Khoi tao mang voi gia tri 0
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            h[j] = (a[i][j] == 0) ? 0 : h[j] + 1;
        }
        ans = max(ans, compute());
    }
    cout << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}

