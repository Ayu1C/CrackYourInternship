class Solution {
public:
     
    bool palindrome(string& s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int f(int index, int n, string& s, vector<int>& dp)
    {
       if(index==n)
       {
           return 0;
       }
        
        if(dp[index] != -1) return dp[index];
        
        int mini = INT_MAX;
        
        for(int i=index; i<s.length(); i++)
        {
            if(palindrome(s, index, i))
            {
               int cost = 1 + f(i+1, n, s, dp);
               mini = min( cost, mini);
            }
        }
        
        return dp[index] = mini;
    }
    
    int minCut(string s) {
        
        int n = s.length();
        
        vector<int> dp(n, -1);
        
         return f(0, n, s, dp) - 1;
    }
};