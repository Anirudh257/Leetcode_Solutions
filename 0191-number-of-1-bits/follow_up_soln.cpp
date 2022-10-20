class Solution {
public:
    int hammingWeight(uint32_t n) {
        // In case of multiple calls to the function, we can use memoization to store the #bits for a particular number to allow for O(1) retrieval.
        // Time complexity: O(1), Space complexity: O(1)
        precompute();
        return f[n/len] + f[n % len];
    }
private:
    static const int len = 1<<16;
    int f[len];
    void precompute() {
        f[0] = 0;
        for (int i = 1; i < len; i++) {
            f[i] = f[i >> 1] + (i & 1);
        }
    }
};
