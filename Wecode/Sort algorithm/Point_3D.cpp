#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y, z;
};

bool shouldComeBefore(const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        if (a.y != b.y) {
            return a.y > b.y;
        } else {
            return a.z < b.z;
        }
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

void mergeSort(vector<Point> &points, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(points, l, mid);
    mergeSort(points, mid + 1, r);
    merge(points, l, mid, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    
    mergeSort(points, 0, N-1);
    
    for (const auto &p : points) {
        cout << p.x << " " << p.y << " " << p.z << "\n";
    }
    
    return 0;
}