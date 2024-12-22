#include<bits/stdc++.h>
using namespace std;

int n, a[50][50], visited[50] = {0}, x[50];
int cmin = INT_MAX;
int f = 0;
int f_best = INT_MAX;

bool check(int v, int k){
    if(visited[v]) return false;
    return true;
}

void solution(){
    if (f + a[x[n]][1] < f_best) {
    f_best = f + a[x[n]][1];
    }
}

void Try(int k){
    for(int v = 2; v <= n ; v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;
            f += a[x[k-1]][x[k]];
            if (k == n) solution();
            else if (f + (n - k) * cmin < f_best) Try(k+1);
            visited[v] = false;
            f -= a[x[k-1]][x[k]];
        }
    }
}

int main(){
    cin >> n;
    for(int i =1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i != j && (cmin > a[i][j])) cmin = a[i][j];
        }
    }
    x[1] = 1;
    Try(2);
    cout << f_best;
}
