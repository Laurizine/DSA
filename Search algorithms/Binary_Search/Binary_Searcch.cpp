// Thuật toán tìm kiếm nhị phân sử dụng khi nào?
// --->  Khi mảng đã được sắp xếp
// Độ phức tạp thời gian: O(log(n))
// Độ phức tạp không gian: O(1)
// Đây là một ví dụ về cách tìm kiếm nhị phân trong C++:

#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2; // Tránh tràn số nguyên
        if (A[m] == x) return m;
        if (x < A[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main() {
    int A[] = {1, 3, 5, 6, 7, 12, 171, 777, 15}; // Mảng phải sắp xếp
    int n = sizeof(A) / sizeof(A[0]);
    int x = 7;

    int result = binarySearch(A, n, x);

    if (result != -1)
        cout << "Phần tử " << x << " được tìm thấy tại vị trí: " << result << endl;
    else
        cout << "Phần tử " << x << " không tồn tại trong mảng." << endl;

    return 0;
}