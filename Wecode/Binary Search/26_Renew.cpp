#include <iostream>
using namespace std;

typedef long long ll;

// Hàm kiểm tra số ngày d có đủ để chặt hết n cây không
bool chat(ll d, ll a, ll k, ll b, ll m, ll n) {
    ll trees_cut = a * (d - d / k) + b * (d - d / m);
    return trees_cut >= n;
}

int main() {
    ll a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;
    
    ll left = 1, right = n / (a + b) * 2 + 1, result = right;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (chat(mid, a, k, b, m, n)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    return 0;
}
