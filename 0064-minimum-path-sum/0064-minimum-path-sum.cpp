class Solution {
public:
    
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        
        if(dp[row][col] != -1) return dp[row][col];
        
        if(row==0 && col==0) return grid[0][0];
        
        if(col-1<0) return f(row-1, col, grid, dp) + grid[row][col];
        if(row-1<0) return f(row, col-1, grid, dp) + grid[row][col];
        
        int left = f(row, col-1, grid, dp) + grid[row][col];
        int up = f(row-1, col, grid, dp) + grid[row][col];
        
        return dp[row][col] = min(left, up);
    }
        
        
    int minPathSum(vector<vector<int>>& grid) {
    
        int m = grid.size();
        int n = grid[0].size();
        
        //dp[i][j] stores the min path sum to reach grid[i][j] from grid[0][0]
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        
       return f(m-1, n-1, grid, dp);   
         
    }
};