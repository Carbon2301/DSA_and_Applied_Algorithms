#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {4, 1, 1, 2, 1, 1};
    int k = 5; // Điều kiện tổng <= k
    int left = 0, right = 0; // Hai con trỏ
    int sum = 0; // Tổng của dãy con hiện tại
    int max_length = 0; // Độ dài lớn nhất của dãy con thỏa mãn

    // Duyệt qua mảng
    while (right < arr.size()) {
        sum += arr[right];

        // Nếu tổng vượt quá k, thu nhỏ dãy con bằng cách tăng left
        while (sum > k) {
            sum -= arr[left];
            left++;
        }

        // Cập nhật độ dài lớn nhất
        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length << endl;

    return 0;
}
