#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// MEXi lầ số nguyên nhỏ nhất không có trong tập
// VD: trong {1, 2, 5} = S --> MEXi S = 0

void computeMEX(const vector<int>& arr, int n) {
    unordered_set<int> seen;
    vector<int> mex(n);
    int mex_value = 0;
    
    for (int i = 0; i < n; i++) {
        seen.insert(arr[i]);
        while (seen.count(mex_value)) {
            mex_value++;
        }
        mex[i] = mex_value;
    }
    
    for (int i = 0; i < n; i++) {
        cout << mex[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    computeMEX(arr, n);
    return 0;
}