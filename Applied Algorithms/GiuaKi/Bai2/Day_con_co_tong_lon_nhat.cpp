#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = arr[0], current_sum = 0;

    for (int x : arr) {
        current_sum += x;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) current_sum = 0;
    }

    cout << max_sum << endl;
    return 0;
}
