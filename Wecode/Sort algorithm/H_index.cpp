#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> citations(n);
    for (int i = 0; i < n; ++i) {
        cin >> citations[i];
    }

    vector<int> count(n + 2, 0); // Tạo mảng count từ 0 đến n

    for (int c : citations) {
        if (c >= n) {
            count[n]++;
        } else {
            count[c]++;
        }
    }

    int total = 0;
    for (int k = n; k >= 0; --k) {
        total += count[k];
        if (total >= k) {
            cout << k << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}