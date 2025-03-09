#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi hai phần tử
                swap(arr[j], arr[j + 1]);
                swapped = true;

                // In ra mảng sau khi hoán đổi
                for (int k = 0; k < n; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
        // Nếu không có hoán đổi nào xảy ra, mảng đã được sắp xếp
        if (!swapped) {
            break;
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

    // Gọi hàm sắp xếp nổi bọt
    bubbleSort(arr, n);

    return 0;
}