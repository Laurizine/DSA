#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Phần tử cần chèn vào phần đã sắp xếp
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key về phía sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Dịch chuyển phần tử sang phải
            j--;

            // In ra mảng sau mỗi lần dịch chuyển (hoán đổi)
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }

        // Chèn key vào vị trí đúng
        arr[j + 1] = key;

        // In ra mảng sau khi chèn key
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Gọi hàm sắp xếp chèn
    insertionSort(arr, n);

    return 0;
}