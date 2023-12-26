class Solution {
public:
    const int mod = (int)pow(10, 9) + 7; // Modulo value for calculations
    
    int f(int n, int k, int target, vector<vector<int>> &dp)
    {
        if(n==0 && target==0) return 1;
        
        if(target<=0 || n==0) return 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int ans = 0;
        
        for(int val=1; val<=k; val++)
        {
            ans = (ans + f(n-1, k, target-val, dp)) % mod;
        }
        
        return dp[n][target] = ans % mod;
    }
        
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        int res = f(n, k, target, dp);
        
        return res;
        
    }
};