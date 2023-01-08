/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
// Time complexity: O(target), depends on the target, Space complexity: O(1)
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == target) {
            return 0;
        }

        int l = 0, r = 1;

        while(reader.get(r) < target) {
            l = r;
            r <<= 2;
        }

        while(l <= r) {
            int mid = (l + r) >> 1;
            if (reader.get(mid) == target) {
                return mid;
            }
            else if (reader.get(mid) > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }
};
