class Solution{
   public:
        int findDuplicate(vector<int>& nums) {
             // Time complexity: O(N), Space complexity: O(1)
              int size = nums.size();
              int hare = nums[0];
              int tortoise = nums[0];

             do {
                  tortoise = nums[tortoise];
                  hare = nums[nums[hare]];
             } while(hare != tortoise);

            tortoise = nums[0];
            while(hare != tortoise) {
                 tortoise = nums[tortoise];
                 hare = nums[hare];
            }

           return hare;
        }
};
