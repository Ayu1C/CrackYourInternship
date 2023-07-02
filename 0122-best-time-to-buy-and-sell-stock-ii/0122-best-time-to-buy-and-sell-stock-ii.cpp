class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minSofar = prices[0], profitSofar = 0;
        
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]-minSofar > 0)
            {
                profitSofar += prices[i]-minSofar;
                if(i<prices.size()-1) minSofar = prices[i+1];
            }
            if(prices[i]<minSofar) minSofar = prices[i];
        }
        if(profitSofar < 0)return 0;
        else return profitSofar;
    }
};