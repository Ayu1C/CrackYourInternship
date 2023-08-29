class Solution {
public:
    
    //USING MEMOIZATION
    
//     int f(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp)
//     {  
//         if(dp[row][col] != 1e4+1) return dp[row][col];
        
//         if(row==n-1) return triangle[row][col];
        
//         int idx1 = triangle[row][col] + f(row+1, col, triangle, n, dp) ;
//         int idx2 = triangle[row][col] + f(row+1, col+1, triangle, n, dp);
        
//         return dp[row][col] = min(idx1, idx2);
//     }
    
    
//     int minimumTotal(vector<vector<int>>& triangle) {
       
//         int n = triangle.size();

//         vector<vector<int>> dp(n, vector<int>(n, 1e4+1));
        
//         for(int i=0; i<n; i++)
//         {
//             dp[i].resize(i+1);
//         }
        
//         return f(0, 0, triangle, n, dp);
//     }
    
    //USING TABULATION 
    
    int minimumTotal(vector<vector<int>>& triangle){
        
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                dp[i][j] = min(dp[i+1][j] + triangle[i][j], dp[i+1][j+1] + triangle[i][j]);
            }
        }
        
        return dp[0][0];
    }
    
};