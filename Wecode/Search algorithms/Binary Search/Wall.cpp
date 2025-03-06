#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int max_a = *max_element(a.begin(), a.end());
    int max_b = *max_element(b.begin(), b.end());
    int low = 0;
    int high = max_a + max_b;
    int best_h = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int j = 0;
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            if (a[i] < mid) {
                while (j < m && a[i] + b[j] < mid) {
                    j++;
                }
                if (j < m) {
                    j++;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            best_h = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    vector<pair<int, int>> best_pairs;
    best_pairs.reserve(n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < best_h) {
            while (j < m && a[i] + b[j] < best_h) {
                j++;
            }
            if (j < m) {
                best_pairs.emplace_back(i + 1, j + 1);
                j++;
            }
        }
    }

    cout << best_h << " " << best_pairs.size() << '\n';
    for (const auto& p : best_pairs) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}