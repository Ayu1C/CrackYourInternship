class Solution {
public:
    
    int f(int index, int prev_idx, vector<int>& nums, int n, vector<vector<int>>& dp)
    {
        if(index==n)
        {
           return 0;
        }
        
        if(dp[index][prev_idx+1] != -1) return dp[index][prev_idx+1];
        
        int take = 0;
        
        int notTake = 0 + f(index+1, prev_idx, nums, n, dp);
        
        if(prev_idx==-1 || nums[index] > nums[prev_idx])
        {
            take = 1 + f(index+1, index, nums, n, dp);
        }
       
        return dp[index][prev_idx+1] = max(take, notTake);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return f(0, -1, nums, n, dp);
    }
};