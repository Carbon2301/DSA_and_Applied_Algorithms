#include <iostream>
#include <vector>
using namespace std;

int H, W, n;
vector<pair<int, int>> rects;
bool used[10][10];
bool found = false;

bool canPlace(int x, int y, int h, int w) {
    if (x + h > H || y + w > W) return false;
    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + w; j++) {
            if (used[i][j]) return false;
        }
    }
    return true;
}

void place(int x, int y, int h, int w, bool state) {
    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + w; j++) {
            used[i][j] = state;
        }
    }
}

void Try(int k) {
    if (k == n) {
        found = true;
    }

    int h = rects[k].first;
    int w = rects[k].second;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (canPlace(i, j, h, w)) {
                place(i, j, h, w, true);
                Try(k + 1);
                place(i, j, h, w, false);
            }
            if (canPlace(i, j, w, h)) {
                place(i, j, w, h, true);
                Try(k + 1);
                place(i, j, w, h, false);
            }
        }
    }
}

int main() {
    cin >> H >> W;
    cin >> n;
    rects.resize(n);
    for (int i = 0; i < n; i++) {
        int hi, wi;
        cin >> hi >> wi;
        rects[i] = {hi, wi};
    }

    Try(0);
    if (found)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
