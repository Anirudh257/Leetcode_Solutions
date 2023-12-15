#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    long long n;

    cin >> n;

    // Arrangement into two sets of equal sums possible only when the sum of numbers [1, ..., n] is divisible by 2.

    // n(n + 1) % 4 == 0.

    if (n* (n + 1) % 4 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    long long reqSum = n*(n + 1)/4;
    long long sum = 0;
    vector<int> vec;
    
    // Numbers can be from 1, ..., n
    int px = 1;

    // Set can contain either n or (n + 1) but not both
    // The numbers in the set should be pairs (n - 1, 1) or (n - 2, 2)

    if (reqSum % n == 0) {
        vec.push_back(n);
        sum += n;
    }

    // Keep adding numbers in the set till it reaches reqSum
    while(reqSum != sum) {
        if (reqSum % n == 0) {
            vec.push_back(n - px);
            vec.push_back(px);
            sum += n;
        }
        else {
            vec.push_back(n - px + 1);
            vec.push_back(px);
            sum += n + 1;
        }
        px++;
    }

    sort(vec.begin(), vec.end());

    px = 0;
    string secSet;
    int vecSize = vec.size();

    cout << "YES" << endl << vecSize << endl;

    for (int i = 1; i <= n; i++) {
        if (px < vecSize && vec[px] == i) {
            cout << i << " ";
            px++;
        }
        else {
            secSet += to_string(i) + " ";
        }
    }
    cout << endl << n - vecSize << endl << secSet << endl;
    
    return 0;
}