#include <iostream>
#include <stack>
using namespace std;

void decimalToBinary(int n) {
    stack<int> binaryStack;

    // Convert decimal to binary using a stack
    while (n > 0) {
        binaryStack.push(n % 2);
        n /= 2;
    }

    // Print the binary representation
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 100000) {
    }
    decimalToBinary(n);

    return 0;
}