#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3" << endl;
        return 0;
    }

    int st = n;
    while(st > 0) {
        cout << st << " ";
        st -= 2;
    }

    st = n - 1;
    while(st > 0) {
        cout << st << " ";
        st -= 2;
    }
    cout << endl;
    
    return 0;
}