class Solution {
public:
           
    int jump(vector<int>& nums){
        
        int n = nums.size();
        
        vector<int> dp(n, 1e4+1);
        
        dp[0] = 0;
        
         for(int i=0; i<n; i++)
         {
             if(nums[i]+i >= n-1)
             {
                 dp[n-1] = min(dp[i]+1, dp[n-1]);
             }
             else
             {
                 for(int j=i+1; j<=i+nums[i]; j++)
                 {
                     dp[j] = min(dp[j], dp[i]+1);
                 }
             }    
         }
        
        return dp[n-1]; 
        
    }
    
};