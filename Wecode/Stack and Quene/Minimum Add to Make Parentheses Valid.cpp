#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    int count = 0;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                count++;
            }
        }
    }
    return count + st.size();
}

int main() {
    string s;
    cin >> s;
    cout << minAddToMakeValid(s);
    return 0;
}