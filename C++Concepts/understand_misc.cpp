#include<iostream>
#include<vector>
#include<stdio>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    }
    if (p1.second > p2.second) {
        return false;
    }
    if (p1.first > p2.second) {
        return true;
    }
    return false;
}

int main() {
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}}; 

    // Sort it according to the 2nd element
    // If second element is the same, then sort 
    // it according to 1st element but in descending order.

    sort(a, a + 3, comp); // {{4, 1}, {2, 1}, {1, 2}}

    int n = 7;
    int cnt = __builtin_popcount(n); // Number of set bits in '7'

    long long num = 1657923232;
    int cnt = __builtin_popcountll(num); // Number of set bits in num

    string s = "312"; // sort so that all permutations are printed
    sort(s.begin(), s.end());

    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    int maxi = *max_elemet(a, a + n); // get maximum element from the entire array.

    return 0;
}