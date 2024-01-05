class Solution {
public:
    
    int M = 1e9+7;
    
    int f(int s, int e, int k, int i, vector<vector<int>> &dp){
		// base condition
        if(i==0) {
            if(s==e) {
                return 1;
            }
            else return 0;
        }
        
		// optimization
        if(abs(e-s)>i) return 0;
        if(dp[s+1000][i] != -1) {
            return dp[s+1000][i]%M;
        }
        
        // choices
        int left = f(s-1, e, k, i-1, dp)%M;
        int right = f(s+1, e, k, i-1, dp)%M;
        
        return dp[s+1000][i] = (left + right)%M;
    }
    
    int numberOfWays(int s, int e, int k) {
		// big array size to make sure we don't get runtime error
        vector<vector<int>> dp(3000, vector<int>(k+1, -1));
        return f(s, e, k, k, dp);
    }
};


//Wrong ans bcz we need 2d array to record steps(or rem k) also.

// class Solution {
    
//     int count = 0, start, steps;
// public:
    
//     int f(int cur, int end, int remK, vector<int>& dp)
//     {
//         if(cur >= start)
//         {
//             if(dp[cur-start] != -1) return dp[cur-start];
            
//             if(remK==0)
//             {
//                 if(cur == end) return 1;
//                 else return dp[cur-start] = 0;
//             }
            
//             return dp[cur-start] = f(cur+1, end, remK-1, dp) + f(cur-1, end, remK-1, dp);
//         }
        
//         else
//         {
//             if(dp[steps + (start-cur)] != -1) return dp[steps + (start-cur)];
            
//             if(remK==0)
//             {
//                 if(cur == end) return 1;
//                 else return dp[steps + (start-cur)] = 0;
//             }
            
//             return dp[steps + (start-cur)] = f(cur+1, end, remK-1, dp) + f(cur-1, end, remK-1, dp);
//         }
         
//     }
    
//     int numberOfWays(int startPos, int endPos, int k) {
        
//         int range = 2*k + 1;
//         start = startPos;
//         steps = k;
        
//         vector<int> dp(range, -1);
        
//         count = f(startPos, endPos, k, dp);
        
//         return count;
//     }
// };