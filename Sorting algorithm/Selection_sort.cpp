#include <iostream>
using namespace std;

void Selection_Sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Giả sử phần tử nhỏ nhất là phần tử đầu tiên, dùng biên minIndex để lưu vị trí của phần tử nhỏ nhất
        for (int j = i + 1; j < n; j++) { // Duyệt tất cả các phần tử trong mảng vfa cập nhạt chỉ số của phần tử nhỏ nhất
            if (a[j] < a[minIndex]) { // Nếu muốn sắp xếp giảm dần thì chỉ cần đổi dấu 
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a[i], a[minIndex]); // Hoán vị phần tử nhỏ nhất mới tìm được với phần tử đầu tiên
        }
    }
}

// Hàm main để kiểm tra thuật toán
int main(){
    int a[1000], n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;   
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Selection_Sort(a, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}
