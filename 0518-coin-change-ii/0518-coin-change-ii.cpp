class Solution {
public:

    int f(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){
 
           if(ind == 0){
               return (T%arr[0]==0);
           }
           
           if(dp[ind][T]!=-1)
               return dp[ind][T];
               
           int notTaken = f(arr,ind-1,T,dp);
           
           int taken = 0;
           if(arr[ind] <= T)
               taken = f(arr,ind,T-arr[ind],dp);
               
           return dp[ind][T] = taken + notTaken;
    }

    int change(int amount, vector<int>& coins) {
       
        int n= coins.size();
    
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        
        return f(coins, n-1, amount, dp); 
    }
};