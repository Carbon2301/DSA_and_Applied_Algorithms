#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > segments(n); 

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end(), compare);

    int res = 0;
    int last = -1;

    for (size_t i = 0; i < segments.size(); ++i) {
        if (segments[i].first > last) {
            res++;
            last = segments[i].second;
        }
    }

    cout << res << endl;

    return 0;
}

