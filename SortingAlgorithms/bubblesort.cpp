#include<iostream>
#include<vector>
using namespace std;

// Time complexity: O(n^2), Space complexity: O(1)

// In-place algorithm, stable sorting algorithm as relative order is maintained.

class BubbleSort {
public:
    void bSort(vector<int>& arr) {
        int n = arr.size();

        for (int numPass = 0; numPass < n; numPass++) {
            bool flag = false; // If no swap after this pass, already sorted array, no need to check more.
            for (int i = 0; i < n - numPass - 1; i++) { // After i passes, last i elements already sorted
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
        }

        return;
    }
};

int main() {
    vector<int> arr = {3, 4, 1, 9, -3, 9};

    cout << "Array before sorting" << endl;
    for (auto &x : arr) {
        cout << x << " ";
    }
    cout << endl;

    BubbleSort bs;

    bs.bSort(arr);

    cout << "Array after sorting" << endl;
    for (auto &x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}