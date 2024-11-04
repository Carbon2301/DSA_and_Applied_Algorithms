#include <iostream>     
#include <vector>       
#include <cmath>        // Cho hàm log2
#include <algorithm>    // Cho hàm min

using namespace std;

const int MAXN = 100001; 
const int LOG = 20; 

int arr[MAXN];
int st[MAXN][LOG]; 

void build(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = log2(R - L + 1);
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    int n; 
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(n);

    int m; 
    cin >> m;
    int result = 0;

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        result += query(i, j);
    }

    cout << result << endl;
    return 0;
}

