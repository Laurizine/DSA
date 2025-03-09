#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Tìm phần tử nhỏ nhất trong phần chưa sắp xếp
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Nếu phần tử nhỏ nhất không phải là phần tử đầu tiên của phần chưa sắp xếp
        if (minIndex != i) {
            // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của phần chưa sắp xếp
            swap(arr[i], arr[minIndex]);

            // In ra mảng sau khi hoán đổi
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Gọi hàm sắp xếp chọn
    selectionSort(arr, n);

    return 0;
}