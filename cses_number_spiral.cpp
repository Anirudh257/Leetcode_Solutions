#include<iostream>

using namespace std;

int main() {
    int t;
    long long x, y;
    
    cin >> t;

    while(t--) {
        cin >> y >> x;

        if (y > x) {
            if (y % 2) {
                cout << (y - 1)*(y - 1) + 1 + (x - 1);
            }
            else {
                cout << y*y - (x - 1);                
            }
        }
        else {
            if (x % 2) {
                cout << x*x - (y - 1);
            }
            else {
                cout << (x - 1)*(x - 1) + 1 + (y - 1);
            }
        }
        cout << endl;
    }

    return 0;
}