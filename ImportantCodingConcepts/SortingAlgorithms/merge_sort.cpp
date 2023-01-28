#include<iostream>
#include<vector>
using namespace std;

// Time complexity: O(nlogn), Space complexity: O(N) [Size of leftArr & Size of rightArr]

// Not in-place algorithm, stable sorting algorithm

// Uses divide and conquer + Recursion Approach
class MergeSort {
private:
    void merge(vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr) {
        int n = arr.size(), i = 0, j = 0, k = 0, lLen = leftArr.size(), rLen = rightArr.size() ;

        while(i < lLen && j < rLen) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            }
            else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while(i < lLen) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while(j < rLen) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }

        return;
    }

public:
    void mergeSort(vector<int>& arr) {
        int n = arr.size();

        if (n > 1) {
            int mid = n/2;
            vector<int> left(mid);
            vector<int> right(n - mid);

            // Time complexity: O(N)
            for (int i = 0; i < mid; i++) {
                left[i] = arr[i];
            }

            // Time complexity: O(N)
            for (int i = mid; i < n; i++) {
                right[i - mid] = arr[i];
            }

            // Time complexity: O(N/2)
            mergeSort(left);

            // Time complexity: O(N/2)
            mergeSort(right);

            // Time complexity: O(N)
            merge(left, right, arr);

            // No need of left and right array now, can be deleted
            left.erase(left.begin(), left.end());
            right.erase(left.begin(), right.end());
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

    MergeSort mSort;

    mSort.mergeSort(arr);

    cout << "Array after sorting" << endl;
    for (auto &x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
