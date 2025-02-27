#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(const vector<int>& arr, int target) {
    int i = 0;
    while (i < arr.size() && arr[i] != target) { // Điều kiện dừng rút gọn
        i++;
    }
    return (i < arr.size()) ? i : -1; // Nếu i chưa vượt quá size, trả về i, ngược lại trả về -1
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // Dùng vector thay vì mảng tĩnh
    int target = 7;

    int result = LinearSearch(arr, target);

    if (result != -1) { // Kiểm tra kết quả
        cout << "Phần tử " << target << " được tìm thấy tại vị trí: " << result << endl;
    } else {
        cout << "Phần tử " << target << " không tồn tại trong vector." << endl;
    }

    return 0;
}
// Output:Độ phức tạp vẫn là O(n) nhưng cách viết này giúp code ngắn gọn hơn.
// Phần tử 7 được tìm thấy tại vị trí thứ 3 trong vector.
// Để tìm kiếm phần tử 7 trong vector, ta cần duyệt qua từng phần tử của vector và so sánh với phần tử cần tìm. 
// Khi tìm thấy phần tử cần tìm, trả về vị trí của phần tử đó. Nếu không tìm thấy, trả về -1.