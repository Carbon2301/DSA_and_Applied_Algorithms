#include <bits/stdc++.h>
#define ft(i,x,y) for(int i = x; i <= y; i++)
using namespace std;

int n, m;
int num[100001], low[100001], cnt = 0;
bool critical_point[100001];

int p[100001];
int c[100001], N = 0;
vector<int> X[100001];

int edge = 0;
int point = 0;

stack<int> st;
void run(int u)
{
    num[u] = low[u] = ++cnt;
    st.push(u);
    int numChild = 0;

    for (int v : X[u])
    {
        if (p[u] == v) continue;
        if (num[v])
        {
            low[u] = min(low[u], num[v]);
        }
        else
        {
            p[v] = u;
            run(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u])
    {
        int v;
        N++;
        do
        {
            v = st.top();
            st.pop();
            low[v] = num[v] = 1e9;
            c[v] = N;
        } while (v != u);
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
    }

    ft(i, 1, n)
    {
        p[i] = i;
    }

    ft(i, 1, n)
    {
        if (!num[i]) run(i);
    }

    cout << N;
    return 0;
}
