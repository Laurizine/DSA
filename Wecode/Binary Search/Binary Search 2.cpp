#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm tìm kiếm nhị phân trên mảng chuỗi
int BinarySearch(const vector<string>& arr, const string& x, int &dem) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        dem++; // Tăng biến đếm mỗi khi kiểm tra phần tử
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) return mid; // Tìm thấy x, trả về vị trí
        if (arr[mid] < x) left = mid + 1; // Tìm kiếm bên phải
        else right = mid - 1; // Tìm kiếm bên trái
    }

    return -1; // Không tìm thấy x
}

int main() {
    int N;
    cin >> N;
    
    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // Nhập từng chuỗi (do độ dài ≤ 10 nên không cần `getline`)
    }

    string x;
    cin >> x; // Nhập chuỗi cần tìm

    int dem = 0; // Biến đếm số lần duyệt
    int kq = BinarySearch(arr, x, dem); // Gọi hàm tìm kiếm nhị phân

    cout << kq << "\n"; // Xuất kết quả vị trí
    if (kq != -1) cout << dem << "\n"; // Xuất số lần duyệt nếu tìm thấy

    return 0;
}
