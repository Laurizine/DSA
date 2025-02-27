// Output
// Phần tử 7 được tìm thấy tại vị trí: 3
// Độ phức tạp thời gian: O(log(log(n)))
// Độ phức tạp không gian: O(1)
// Đây là một ví dụ về cách tìm kiếm nội suy trong C++. Trong trường hợp tốt nhất, 
// Độ phức tạp thời gian của thuật toán tìm kiếm nội suy là O(log(log(n))), trong trường hợp xấu nhất là O(n), và trung bình là O(log(log(n))).
// Độ phức tạp không gian của thuật toán là O(1).

#include <iostream>
using namespace std;

int interpolationSearch(int A[], int n, int x) {
    int l = 0, r = n - 1;

    while (l <= r && x >= A[l] && x <= A[r]) {
        // Dự đoán vị trí
        int pos = l + ((double)(r - l) / (A[r] - A[l])) * (x - A[l]);

        // Nếu tìm thấy phần tử
        if (A[pos] == x)
            return pos;

        // Nếu x lớn hơn, bỏ phần bên trái
        if (A[pos] < x)
            l = pos + 1;
        else // Nếu x nhỏ hơn, bỏ phần bên phải
            r = pos - 1;
    }
    return -1; // Không tìm thấy
}

int main() {
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15}; // Mảng đã sắp xếp
    int n = sizeof(A) / sizeof(A[0]);
    int x = 7;

    int result = interpolationSearch(A, n, x);

    if (result != -1)
        cout << "Phần tử " << x << " được tìm thấy tại vị trí: " << result << endl;
    else
        cout << "Phần tử " << x << " không tồn tại trong mảng." << endl;

    return 0;
}