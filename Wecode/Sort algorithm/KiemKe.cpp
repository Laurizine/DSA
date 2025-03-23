#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<string> codes(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> codes[i];
    }
    
    int uniqueCount = 0;
    for (int i = 0; i < N; ++i) {
        bool isUnique = true;
        // Kiểm tra xem mã codes[i] đã xuất hiện trước vị trí i chưa
        for (int j = 0; j < i; ++j) {
            if (codes[i] == codes[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueCount++;
        }
    }
    
    cout << uniqueCount;
    
    return 0;
}