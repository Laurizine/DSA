#include <iostream>
#include <vector>
using namespace std;
// Khai báo hàm tìm kiếm tuyến tính LinearSearch : vector<Kiểu DL> Tên_biến.


int LinearSearch(const vector<int>& arr, int target) { // target là chuỗi cần tìm kiếm
    int i = 0;
    while (i < arr.size()) { // Sử dụng vòng lặp while
        if (arr[i] == target) { // Kiểm tra nếu tìm thấy phần tử
            return i; // Trả về vị trí tìm thấy
        }
        i++; // Tăng chỉ số để kiểm tra phần tử tiếp theo
    }
    return -1; // Trả về -1 nếu không tìm thấy phần tử
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 12;

    int result = LinearSearch(arr, target);

    if (result != -1) { // Kiểm tra kết quả
        cout << "Phần tử " << target << " được tìm thấy tại vị trí: " << result << endl;
    } else {
        cout << "Phần tử " << target << " không tồn tại trong vector." << endl;
    }

    return 0;
}
