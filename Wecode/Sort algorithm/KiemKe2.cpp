#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool naturalCompare(const string &a, const string &b) {
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

template <typename T, typename Compare>
void mergeOrder(vector<T>& arr, int left, int mid, int right, Compare cmp) {
    int n = right - left + 1;
    vector<T> temp(n);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(cmp(arr[i], arr[j]))
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    for(int t = 0; t < n; t++){
        arr[left + t] = temp[t];
    }
}

template <typename T, typename Compare>
void mergeOrderRecursive(vector<T>& arr, int left, int right, Compare cmp) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeOrderRecursive(arr, left, mid, cmp);
        mergeOrderRecursive(arr, mid + 1, right, cmp);
        mergeOrder(arr, left, mid, right, cmp);
    }
}

// HÃ m chÃ­nh Äá» "sáº¯p xáº¿p" (arrange) vector theo tiÃªu chÃ­ cho trÆ°á»c.
template <typename T, typename Compare>
void arrange(vector<T>& arr, Compare cmp) {
    if(!arr.empty())
        mergeOrderRecursive(arr, 0, arr.size() - 1, cmp);
}

struct PairCompare {
    bool operator()(const pair<string,int>& a, const pair<string,int>& b) const {
        if(a.second != b.second) return a.second > b.second;
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
        return a.first < b.first;
    }
};

int main(){

    int N;
    cin >> N;
    cin.ignore();
    
    vector<string> all_codes;
    all_codes.reserve(N);
    
    string code;
    for(int i = 0; i < N; i++){
        getline(cin, code);
        all_codes.push_back(code);
    }
    

    vector<pair<string,int>> result;
    for (int i = 0; i < all_codes.size(); ) {
        string current = all_codes[i];
        int count = 0;
        while(i < all_codes.size() && all_codes[i] == current) {
            count++;
            i++;
        }
        result.push_back({current, count});
    }
    
    arrange(result, PairCompare());
    
    for(const auto &p : result){
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}