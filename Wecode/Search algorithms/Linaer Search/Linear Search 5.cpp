#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << max_weight(A, N) << "\n";
    }
    return 0;
}

int max_weight(vector<int>& A, int N) {
    sort(A.begin(), A.end());
    int minA = A[0], maxA = A[N - 1];

    // Trường hợp 1: Dãy S1 chứa phần tử nhỏ nhất, dãy S2 chứa phần tử lớn nhất
    int option1 = (maxA - A[1]) + (A[N - 2] - minA);

    // Trường hợp 2: Dãy S1 chứa phần tử lớn nhất, dãy S2 chứa phần tử nhỏ nhất
    int option2 = (maxA - minA) + 0;  // Một dãy chứa cả min và max, dãy còn lại trống

    return max(option1, option2);
}