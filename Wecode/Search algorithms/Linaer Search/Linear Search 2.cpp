#include <iostream>
#include <vector>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    vector<pair<int, int>> results; // Lưu vị trí và số lần duyệt
    int count = 0;

    // Duyệt từ trái sang phải
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            results.push_back({i, i + 1}); // Vị trí và số lần duyệt
            count++;
        }
    }

    // Xuất số lần tìm thấy
    cout << count << endl;
    
    // Xuất vị trí và số lần duyệt
    for (auto &res : results) {
        cout << res.first << " " << res.second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    linearSearch(arr, n, key);
    return 0;
}