class Solution {
public:
    int M=1e9+7;
    // time complexity: O(N), Space complexity: O(N)
    int countTexts(string s) {
        int n=s.size();
        vector<long long> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            //firstly if character is same or different then copy last value.
            dp[i]=dp[i-1];
            //if last two characters are same then also last that value.
            if((i-2)>=0 && s[i-1]==s[i-2])
                dp[i]=(dp[i]+dp[i-2])%M;
            else
                continue;
            //if last 3 characters are same then also add that value.
            if((i-3)>=0 && s[i-1]==s[i-3])
                dp[i]=(dp[i]+dp[i-3])%M;
            else
                continue;
            //if we have 7 or 9 as characters we have to also check for 4th character.
            if((s[i-1]=='7' || s[i-1]=='9') && (i-4)>=0 && s[i-1]==s[i-4])
                dp[i]=(dp[i]+dp[i-4])%M;
        }
        return dp[n]%M;
    }
};
