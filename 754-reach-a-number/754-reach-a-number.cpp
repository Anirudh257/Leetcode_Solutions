class Solution {
public:
    int reachNumber(int target) {
        // Time complexity: O(log(target)), Space complexity: O(1)
        int numSteps = 0, currSum = 0;
        
        if (target == 0) {
            return 0;
        }
        
        target = abs(target);
        
        while(currSum < target) {
            currSum += numSteps;
            numSteps++;
        }
        
        if (currSum == target) {
            return numSteps - 1;
        }
        
        while((currSum - target)%2 == 1) {
            currSum += numSteps;
            numSteps++;
            
        }
        
        return numSteps - 1;
    }
};