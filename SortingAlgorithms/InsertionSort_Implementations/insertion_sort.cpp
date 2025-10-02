#include<iostream>
#include<vector>
using namespace std;

// Time complexity: O(n^2), Space complexity: O(1)

// In-place algorithm, stable sorting algorithm
class InsertionSort {
public:
    void insSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int val = arr[i];
            int hole = i; // Everything to the left of hole is considered sorted, insert val in the correct
            // position in subarr[0:i - 1]

            while(hole > 0 && arr[hole - 1] > val) {
                arr[hole] = arr[hole - 1];
                hole--;
            }
            arr[hole] = val;
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

    InsertionSort iSort;

    iSort.insSort(arr);

    cout << "Array after sorting" << endl;
    for (auto &x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}