class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        
         int n=text1.size();
         int m=text2.size();
     
         vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
         
         for(int ind1=1; ind1<=n; ind1++){
             
             for(int ind2=1; ind2<=m; ind2++){
                 
                if(text1[ind1-1] == text2[ind2-1])
                     dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
    
                else 
                   dp[ind1][ind2] = 0 + max(dp[ind1][ind2-1], dp[ind1-1][ind2]);
             }
         }
        
        return dp[n][m];
             
    }
    
    int minDistance(string word1, string word2) {
        
         int n=word1.size();
         int m=word2.size(); 
        
         int lcs = longestCommonSubsequence(word1, word2);
         
        return n  + m - 2 * lcs;
    }
};