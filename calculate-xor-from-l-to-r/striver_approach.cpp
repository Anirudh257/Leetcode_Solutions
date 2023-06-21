#include<iostream>

using namespace std;

int compXOR(int n) {
    if (n % 4 == 0) {
        return n;
    }
    else if (n % 4 == 1) {
        return 1;
    }
    else if (n % 4 == 2) {
        return n + 1;
    }
    return 0;
}

int main() {
    int l = 5;
    int r = 6;

    int xorL_1 = compXOR(l - 1);
    int xorR = compXOR(r);
    int ans = xorL_1^xorR;

    cout << ans << endl;

    return 0;
}