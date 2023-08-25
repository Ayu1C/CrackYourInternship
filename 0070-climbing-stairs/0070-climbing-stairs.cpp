class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1);
        dp[1] = 1;
        if(dp.size()>2) dp[2] = 2;
        
        for(int i=3; i<n+1; i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
};