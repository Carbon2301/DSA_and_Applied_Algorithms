#include<bits/stdc++.h>
using namespace std;
int n, a[100], b[100], c[100], S;
int main(){
    cin >> n;
    for (int i = 0; i < n ; i++){
        cin >> a[i];
        b[a[i]]++;
    }

    for(int i = 0; i < n ; i ++){
        if (b[i] > 1){
        S += b[i] * (b[i] - 1) / 2;
        }
    }
    cout << S;
}
