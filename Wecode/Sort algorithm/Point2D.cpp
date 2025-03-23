#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool shouldComeBefore(const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.y > b.y;
    }
}

void merge(vector<Point> &points, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<Point> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = points[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = points[mid + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (shouldComeBefore(L[i], R[j])) {
            points[k] = L[i];
            i++;
        } else {
            points[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
        points[k++] = L[i++];
    while (j < n2)
        points[k++] = R[j++];
}

void mergeSortIterative(vector<Point> &points) {
    int n = points.size();
    for (int currentSize = 1; currentSize < n; currentSize *= 2) {
        for (int leftStart = 0; leftStart < n; leftStart += 2 * currentSize) {
            int mid = leftStart + currentSize - 1;
            if (mid >= n - 1) break;
            int rightEnd = min(leftStart + 2 * currentSize - 1, n - 1);
            merge(points, leftStart, mid, rightEnd);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    mergeSortIterative(points);
    
    for (const auto &p : points) {
        cout << p.x << " " << p.y << "\n";
    }
    
    return 0;
}