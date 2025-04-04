#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> splitComponents(const string& s) {
    vector<string> components;
    string current;
    for (char c : s) {
        if (c == '/') {
            if (!current.empty()) {
                components.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        components.push_back(current);
    }
    return components;
}

string cleanUnixPath(const string& path) {
    if (path.empty()) return ".";

    bool is_absolute = (path[0] == '/');
    vector<string> components = splitComponents(path);
    
    stack<string> st;
    for (const string& comp : components) {
        if (comp == ".") {
            continue;
        } else if (comp == "..") {
            if (is_absolute) {
                if (!st.empty()) st.pop();
            } else {
                if (!st.empty() && st.top() != "..") {
                    st.pop();
                } else {
                    st.push("..");
                }
            }
        } else {
            st.push(comp);
        }
    }
    
    vector<string> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    
    string cleaned;
    if (is_absolute) {
        cleaned = "/";
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) cleaned += "/";
            cleaned += result[i];
        }
    } else {
        if (result.empty()) {
            cleaned = ".";
        } else {
            for (size_t i = 0; i < result.size(); ++i) {
                if (i > 0) cleaned += "/";
                cleaned += result[i];
            }
            // Thêm './' nếu đường dẫn gốc bắt đầu bằng './' và kết quả không phải '..'
            if (path.size() >= 2 && path.substr(0, 2) == "./" && result[0] != "..") {
                cleaned = "./" + cleaned;
            }
        }
    }
    
    // Xóa '/' cuối cùng nếu có và không phải là root
    if (cleaned.size() > 1 && cleaned.back() == '/') {
        cleaned.pop_back();
    }
    
    return cleaned;
}

int main() {
    string s;
    getline(cin, s);
    cout << cleanUnixPath(s) << endl;
    return 0;
}