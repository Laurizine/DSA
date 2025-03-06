#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long left = 0, right = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        right += a[i];
        if (a[i] > left) {
            left = a[i];
        }
    }
    
    while (left < right) {
        long long mid = (left + right) / 2;
        int cnt = 1;
        long long current_sum = 0;
        
        for (long long num : a) {
            if (current_sum + num > mid) {
                ++cnt;
                current_sum = num;
            } else {
                current_sum += num;
            }
        }
        
        if (cnt <= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}