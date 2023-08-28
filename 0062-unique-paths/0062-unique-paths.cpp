class Solution {
public:
//     int f(int row, int col, vector<vector<int>>& dp)
//     {
        
//         if(row<0 || col<0) return 0;
        
//         if(dp[row][col] != -1) return dp[row][col];
        
//         if(row==0 && col==0) return 1;
        
//         int right = f(row, col-1, dp);
//         int down = f(row-1, col, dp);
        
//         return dp[row][col] = right+down;
//     }

    int uniquePaths(int m, int n) {
        
        if((m==1 && n==1) || (m==1 && n==2) || (m==2 && n==1)) return 1;
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //dp[i][j] stores the number of unique paths to reach grid[i][j] from grid[0][0]
         
        dp[0][0] = 1;
        
        for(int i=0; i<m; i++)
        {      
            for(int j=0; j<n; j++)
            {
                if(j-1>=0) dp[i][j] += dp[i][j-1];
                
                if(i-1>=0) dp[i][j] += dp[i-1][j];
            }
        }
            
         return dp[m-1][n-1];   
    }
    
};