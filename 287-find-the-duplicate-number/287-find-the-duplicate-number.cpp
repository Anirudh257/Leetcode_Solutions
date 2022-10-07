class Solution{
   public:
        int findDuplicate(vector<int>& nums) {
              int size = nums.size();
              int freq[size + 1];
            
              for (int i = 1; i <= size; i++) {
                  freq[i] = 0;
              }
              
              // for (int n : freq) {
              //     cout << n << endl;
              // }
               
              for (int n : nums) {
                   freq[n]++;
                   if (freq[n] > 1) {
                       return n;
                   }
              }
            
            
              return -1;
        }
};
