#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1000001;
const int LOGN = 20;  

int st[MAXN][LOGN];
int logs[MAXN];

void preprocess(const vector<int>& arr) {
    int n = arr.size();
    
    logs[1] = 0;
    for (int i = 2; i <= n; i++) {
        logs[i] = logs[i/2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

int query(int L, int R) {
    int j = logs[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    preprocess(arr);

    int m;
    cin >> m;

    long long Q = 0;
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        Q += query(i, j);
    }

    cout << Q << endl;

    return 0;
}
