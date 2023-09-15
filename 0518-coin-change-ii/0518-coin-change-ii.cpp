class Solution {
public:

    int change(int amount, vector<int>& coins) {
       
        int n= coins.size();
    
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for(int T=0; T<=amount; T++)
        {
            if(T % coins[0]==0)
                dp[0][T] = 1;
        }
        
        for(int idx=1; idx<n; idx++)
        {
            for(int tar = 0; tar <= amount; tar++)
            {
                int notTaken = dp[idx-1][tar];
           
                int taken = 0;
                if(coins[idx] <= tar)
                    taken = dp[idx][tar-coins[idx]];
               
                dp[idx][tar] = taken + notTaken;
            }
        }
        
        return dp[n-1][amount]; 
    }
};