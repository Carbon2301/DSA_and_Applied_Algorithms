#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

int solve(int n, int k, vector<vector<int> > &c) {
    vector<vector<int> > dp(1 << n, vector<int>(n + 1, INF));
    dp[0][0] = 0;  

  
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n + 1; ++i) {
            if (dp[mask][i] == INF) continue; 

   
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue; 

 
                int nextMask = mask | (1 << j);
                int pickUpToDestination = c[i][j + 1] + c[j + 1][j + n];
                dp[nextMask][j + 1] = min(dp[nextMask][j + 1], dp[mask][i] + pickUpToDestination);
            }
        }
    }

    return dp[(1 << n) - 1][n];  
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > c(2 * n + 1, vector<int>(2 * n + 1));

    
    for (int i = 0; i < 2 * n + 1; ++i) {
        for (int j = 0; j < 2 * n + 1; ++j) {
            cin >> c[i][j];
        }
    }


    int result = solve(n, k, c);

    
    cout << n << endl;
    cout << result << endl;

    return 0;
}

