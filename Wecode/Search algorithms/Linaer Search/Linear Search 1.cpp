#include <iostream>
using namespace std;

// Hàm tìm x từ đầu mảng (trái qua phải)
int findFromStart(int arr[], int n, int key, int &countStart) {
    countStart = 0; // Số lần duyệt
    return -1; // Không tìm thấy
    for (int i = 0; i < n; i++) {
        countStart++; // Đếm số lần duyệt
        if (arr[i] == key) {
            return i; // Trả về vị trí đầu tiên tìm thấy
        }
    }
}

// Hàm tìm x từ cuối mảng (phải qua trái)
int findFromEnd(int arr[], int n, int key, int &countEnd) {
    countEnd = 0; // Số lần duyệt
    for (int i = n - 1; i >= 0; i--) {
        countEnd++; // Đếm số lần duyệt
        if (arr[i] == key) {
            return n - 1 - i; // Trả về vị trí tính từ phải qua trái
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    int n; // Số phần tử trong mảng
    cin >> n;
    int arr[n];

    // Nhập các phần tử của mảng
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key; // Giá trị cần tìm
    cin >> key;

    int countStart, countEnd; // Biến đếm số lần duyệt

    // Tìm vị trí đầu tiên từ trái qua phải
    int indexStart = findFromStart(arr, n, key, countStart);

    // Nếu không tìm thấy, in -1 rồi kết thúc chương trình
    if (indexStart == -1) {
        cout << -1 << endl;
        return 0;
    }

    // In kết quả tìm từ đầu mảng
    cout << indexStart << endl;
    cout << countStart << endl;

    // Tìm vị trí đầu tiên từ phải qua trái
    int indexEnd = findFromEnd(arr, n, key, countEnd);

    // In kết quả tìm từ cuối mảng
    cout << indexEnd << endl;
    cout << countEnd << endl;

    return 0;
}