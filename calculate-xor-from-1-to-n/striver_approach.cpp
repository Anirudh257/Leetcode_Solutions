#include<iostream>
using namespace std;

// Time complexity: O(1), Space complexity: O(1)
int main() {
    int n = 5;

    if (n % 4 == 0) {
        cout << n << endl;
    }
    else if (n % 4 == 1) {
        cout << 1  << endl;
    }
    else if (n % 4 == 2) {
        cout << n + 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}