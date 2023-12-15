// Time complexity: O(N), Space complexity: O(1)

#include<iostream>

using namespace std;

int main() {

    long long n;
    cin >> n;

    long long num;
    long long currSum = 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        currSum += num;
    }

    long long actSum = (n * (n + 1))/2;

    cout << actSum - currSum << endl;

    return 0;
}