#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int N, T, D;
int arr[MAX], t[MAX];
int f[MAX][101];

void input()
{
    cin >> N >> T >> D;
    arr[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }
}

void solve()
{
    for (int k = 1; k <= T; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (k < t[i])
            {
                f[i][k] = 0;
            }
            else
            {
                int ans = 0;
                for (int j = i - D; j <= i - 1; j++)
                {
                    if (j <= 0)
                    {
                        ans = max(ans, arr[i]);
                    }
                    else
                    {
                        ans = max(ans, arr[i] + f[j][k - t[i]]); 
                    }
                }
                f[i][k] = ans;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            ans = max(ans, f[i][j]);
        }
    }

    cout << ans;
}
int main()
{
    input();
    solve();
    return 0;
}
