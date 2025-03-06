#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long N) {
    if (N <= 1) return false;
    if (N <= 3) return true; // 2 and 3 are primes
    if (N % 2 == 0) return false;
    long long sqrt_n = sqrt(N);
    for (long long i = 3; i <= sqrt_n; i += 2) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

long long findA(long long N) {
    long long sqrt_n = sqrt(N);
    for (long long i = sqrt_n; i >= 3; --i) {
        if (N % i == 0) {
            long long b = N / i;
            if (b >= 3) {
                return i;
            }
        }
    }
    return -1;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        long long N = 4 * k - 1;
        if (N < 9) {
            cout << "-1 -1\n";
            continue;
        }
        if (isPrime(N)) {
            cout << "-1 -1\n";
            continue;
        }
        long long a = findA(N);
        if (a == -1) {
            cout << "-1 -1\n";
            continue;
        }
        long long b = N / a;
        long long m = (a - 1) / 2;
        long long n = (b - 1) / 2;
        cout << m << " " << n << "\n";
    }
}

int main() {
    solve();
    return 0;
}