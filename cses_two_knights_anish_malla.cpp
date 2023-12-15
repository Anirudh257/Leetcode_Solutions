#include<iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    // There are n*n possibilities for keeping 2 knights. == n**2C2
    // Only invalid possibilities are grids of size 2 x 3 and 3 x 2 where there are 2 invalid possibilities in both respectively.
    // Total (2 x 3) grids in n*n is (n - 1)*(n - 2) [vertical and horizontal sliding]
    // Total (3 x 2) grids in n*n is (n - 2)*(n - 1) [vertical and horizontal sliding]
    // Total invalid possibilities is: 2*2*(n - 1)(n - 2) = 4 * (n - 1)(n - 2)

    for (long long i = 1; i <= n; i++) {
        long long totPoss = ((i*i)*(i*i - 1))/2;
        long long invalidPoss = 4*(i - 1)*(i - 2);

        cout << totPoss - invalidPoss << endl;   

    }


    return 0;
}