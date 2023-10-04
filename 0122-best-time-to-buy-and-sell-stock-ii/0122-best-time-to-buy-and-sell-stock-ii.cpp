class Solution {
public:
    
    long f(int idx, int buy, vector<int>& prices, int n, vector<vector<int>>& dp)
    {
        if(idx == n) return 0;
        
        long profit = 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy)
        {
            profit = max(-prices[idx] + f(idx+1, 0, prices, n, dp), 0 + f(idx+1, 1, prices, n, dp));
        }
        else
        {
            profit = max(prices[idx] + f(idx+1, 1, prices, n, dp), 0 + f(idx+1, 0, prices, n, dp));
        }
        
        return dp[idx][buy] =  profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        
//         METHOD 1
            
//         int minSofar = prices[0], profitSofar = 0;
        
//         for(int i=1; i<prices.size(); i++)
//         {
//             if(prices[i]-minSofar > 0)
//             {
//                 profitSofar += prices[i]-minSofar;
                
//                 //bcz we can hold only one stock at a time, so after selling a stock only we could buy another, so we update our minSofar to next day after selling current stock;
                
//                 if(i<prices.size()-1) minSofar = prices[i+1];
//             }
//             if(prices[i]<minSofar) minSofar = prices[i];
//         }
        
//         if(profitSofar < 0)return 0;
//         else return profitSofar;
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return f(0, 1, prices, n, dp);
    }
};