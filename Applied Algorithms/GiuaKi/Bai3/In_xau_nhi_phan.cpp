#include<bits/stdc++.h>

using namespace std;
int N;
int X[100];

void show(int N){
    for(int i = 1; i <= 3; i++){
    cout << X[i];
}
    cout <<endl;
}

int Try(int i){
    for(int j = 0; j <=1; j++){
        X[i] = j;
        if (i == N){
            show(N);
        } else {
            Try(i+1);
        }
    }
}

int main(){
    cin >> N;
    Try(1);
}
