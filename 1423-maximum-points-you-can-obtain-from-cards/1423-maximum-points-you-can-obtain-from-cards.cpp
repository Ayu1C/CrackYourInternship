class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         
        int ans, curSum, total = 0;
        
        for(int i=0; i<k; i++)
        {
           total+=cardPoints[i];
        }
        
        curSum = total;
        ans = total;
        
        for(int i=k-1; i>=0; i--)
        {
           curSum -= cardPoints[i];
            curSum += cardPoints[cardPoints.size()-k+i];
            
            ans = max(ans, curSum);
        }
            
        return ans;
    }
};