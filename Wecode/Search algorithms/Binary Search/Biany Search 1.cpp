#include <iostream>
using namespace std;

// Hàm tìm kiếm nhị phân
int BinarySearch(int arr[], int left, int right, int x, int &dem) {
    dem++;

    if (right >= left) {
        int mid = left + (right - left) / 2; // Tìm phần tử ở giữa

        if (arr[mid] == x) {
            return mid; // Tìm thấy x, trả về vị trí
        }

        if (arr[mid] > x) {
            return BinarySearch(arr, left, mid - 1, x, dem); // Tìm kiếm trong nửa bên trái
        }

        return BinarySearch(arr, mid + 1, right, x, dem); // Tìm kiếm trong nửa bên phải
    }

    return -1; // Không tìm thấy x
}

int main() {
    int N;
    cin >> N; // Nhập kích thước mảng

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // Nhập các phần tử của mảng
    }

    int x;
    cin >> x; // Nhập giá trị cần tìm

    int dem = 0; // Biến đếm số lần duyệt
    int kq = BinarySearch(arr, 0, N - 1, x, dem); // Gọi hàm tìm kiếm nhị phân

    // Xuất kết quả
    if (kq == -1) {
        cout << -1 << endl; // Không tìm thấy
    } else {
        cout << kq << endl; // Vị trí tìm thấy
        cout << dem << endl; // Số lần duyệt
    }

    return 0;
}