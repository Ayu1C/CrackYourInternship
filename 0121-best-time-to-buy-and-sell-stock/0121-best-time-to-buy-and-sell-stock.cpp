class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int maxProfit = 0, profit, minSofar = prices[0];
        
        for(int i=1; i<prices.size(); i++)
        {
           if(prices[i] < minSofar) minSofar = prices[i];
            profit = prices[i] - minSofar;
            
            if(profit > maxProfit) maxProfit = profit;
        }
        return maxProfit;
        
    }
};