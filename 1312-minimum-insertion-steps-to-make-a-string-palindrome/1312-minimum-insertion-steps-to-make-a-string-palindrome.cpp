class Solution {
public:
    int minInsertions(string s) {
         
        string t = s;
        reverse(s.begin(), s.end());
        
        int n = t.size(), m = s.size();
         
        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
         
         for(int ind1=1; ind1<=n; ind1++){
             
             for(int ind2=1; ind2<=m; ind2++){
                 
                if(t[ind1-1] == s[ind2-1])
                     dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
    
                else 
                   dp[ind1][ind2] = 0 + max(dp[ind1][ind2-1], dp[ind1-1][ind2]);
             }
         }
        
        return n - dp[n][m];
    }
};