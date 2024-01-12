class Solution {
public:
    int substr(vector<int>& s, vector<int>& t)
    {
        int sl=s.size();
        int tl=t.size();
        vector<vector<int>> dp(sl+1,vector<int>(tl+1,0));
        int longest=0;
        for(int i=1;i<=sl;i++)
        {
            for(int j=1;j<=tl;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                longest=max(longest, dp[i][j]);
            }
        }
        return longest;
    }
    
    int findLength(vector<int>& a, vector<int>& b) {
        return substr(a,b);
    }
};