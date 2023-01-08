/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
// Time complexity: O(log N), Space complexity: O(1)
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int high = (int)pow(10, 4);
        return binSearch(reader, 0, high - 1, target);
    }
private:
    int binSearch(const ArrayReader& reader, int low, int high, int target) {
        while(low <= high) {
            int mid = (low + high)/2;
            if (reader.get(mid) == INT_MAX) {
                high = mid - 1;
            }
            else {
                if (reader.get(mid) == target) {
                    return mid;
                }
                else if (reader.get(mid) < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
