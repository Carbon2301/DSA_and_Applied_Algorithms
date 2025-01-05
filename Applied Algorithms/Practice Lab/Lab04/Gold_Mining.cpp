#include <bits/stdc++.h>

using namespace std;
const int N = 1000001;
int arr[N];
int n, L1, L2, res;
int F[N];
deque<int> Q;
priority_queue<int> PQ;
typedef pair<int, int> ii;
void input()
{
    fstream fsi("test.txt", ios::in);
    cin >> n >> L1 >> L2;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        F[i] = arr[i];
    }
    Q.push_back(1);
}


void proc2()
{
    priority_queue<ii> hd;
    for (int i = 1; i <= n; i++)
    {
        if (i - L1 > 0)
            hd.push(ii(F[i - L1], i - L1)); 
        while (!hd.empty())
        { 
            if (hd.top().second < i - L2) 

                hd.pop();
            else
                break;
        }
        if (hd.empty())
            F[i] = arr[i];
        else
            F[i] = hd.top().first + arr[i]; // toi uu hoa cong thuc quy hoach dong
        res = max(F[i], res);
    }
    cout << res << "\n";
}
int main()
{
    input();
    for (int i = 1; i <= L1; i++)
    {
        PQ.push(F[i]);
    }

    proc2();
    return 0;
}
