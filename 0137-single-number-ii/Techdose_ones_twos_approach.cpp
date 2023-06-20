class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Only ones contains the element that occurs only once.
        // Time complexity: O(N), Space complexity: O(1)
        // XOR computes bits that occur odd number of times.
        // Only set 1 to bits that occur exactly once.
        // For bits occuring 2 or 3 times, set it 0.
        
        int seenOnce = 0, seenTwo = 0;
        // Want bits only seenOnce

        // seenOnce: seenTwo should be 0
        // If bit = 0 in num and seenOnce = 0 ==> never seen bit till now,
        // solution must be 0.
        // If bit = 0 in num and seenOnce = 1 ==> Have seen atleast once 
        // till now, solution must be 1.
        // If bit = 1 in num and seenOnce = 0 ==> Not seen even once, but
        // just saw now, solution must be 1.
        // If bit = 1 in num and seenOnce = 1 ==> Seen once already, don't
        // want to set bit = 1 again.

        // Hence, seenOnce  = (seenOnce ^ num) & (~seenTwo)

        // seenTwo: seenOnce must be 1

        // If bit = 0 in num and seenTwo = 0 ==> Not seen even once, set to 0
        // if bit = 0 in num and seenTwo = 1 ==> Already seen twice, set it to 1
        // If bit = 1 in num and seenTwo = 0 ==> seen Once already and seeeing now ==> seeing 2 times and set to 1
        // If bit = 1 in num and seenTwo = 1 ==> seenTwo already & another 1 is set >= 2 times => set to 0

        // seenTwo = seenTwo ^ num & ~seenOnce
        for (int n : nums) {
            seenOnce = seenOnce ^ n & ~seenTwo;
            seenTwo = seenTwo ^ n & ~seenOnce;
        }
        return seenOnce;
    }
};