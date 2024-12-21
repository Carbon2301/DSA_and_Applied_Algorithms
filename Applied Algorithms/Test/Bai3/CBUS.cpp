#include<bits/stdc++.h>

using namespace std;

int N, cap;
int A[30][30];
int x[30];
int visited[30] = {0};
int load = 0, f = 0, f_best = INT_MAX, cmin;

void input() {
    cin >> N >> cap;
    cmin = INT_MAX;
    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            cin >> A[i][j];
            if (i != j && cmin > A[i][j]) cmin = A[i][j];
        }
    }
}

int check(int v, int k) {
    return !visited[v] && (v > N ? visited[v - N] : (load + 1 <= cap));
}

void solution() {
    if (f + A[x[2 * N]][0] < f_best) {
        f_best = f + A[x[2 * N]][0];
    }
}

void TRY(int k) {
    for (int v = 1; v <= 2 * N; v++) {
        if (check(v, k)) {
            x[k] = v;
            f += A[x[k - 1]][x[k]];
            load += (v <= N) ? 1 : -1;
            visited[v] = 1;

            if (k == 2 * N) solution();
            else if (f + (2 * N + 1 - k) * cmin < f_best) TRY(k + 1);

            load += (v <= N) ? -1 : 1;
            visited[v] = 0;
            f -= A[x[k - 1]][x[k]];
        }
    }
}

int main() {
    input();
    TRY(1);
    cout << f_best;
    return 0;
}
