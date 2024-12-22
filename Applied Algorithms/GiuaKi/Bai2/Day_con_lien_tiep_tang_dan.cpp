#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 1, 2, 3, 4};
    int count = 0, length = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            length++;
        } else {
            count += (length * (length + 1)) / 2; // Tổng dãy con tăng
            length = 1;
        }
    }

    count += (length * (length + 1)) / 2; // Thêm dãy cuối cùng
    cout << count << endl;
    return 0;
}
