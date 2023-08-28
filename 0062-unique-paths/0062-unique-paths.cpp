class Solution {
public:
//     int f(int row, int col, vector<vector<int>>& dp)
//     {
        
//         if(row<0 || col<0) return 0;
        
//         if(dp[row][col] != -1) return dp[row][col];
        
//         if(row==0 && col==0) return 1;
        
//         int left = f(row, col-1, dp);
//         int up = f(row-1, col, dp);
        
//         return dp[row][col] = left+up;
//     }

    int uniquePaths(int m, int n) {
        
        if((m==1 && n==1) || (m==1 && n==2) || (m==2 && n==1)) return 1;
        
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //dp[i][j] stores the number of unique paths to reach grid[i][j] from grid[0][0]
         
        
        vector<int> prev(n,0);
        
        for(int i=0; i<m; i++)
        {   
            vector<int> temp(n,0);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0){
                    temp[0] = 1;
                    continue;
                }
                int cur = prev[j];
                if(j-1>=0) cur += temp[j-1];
                temp[j] = cur;
            }
            prev = temp;
        }
            
         return prev[n-1];   
    }
    
};