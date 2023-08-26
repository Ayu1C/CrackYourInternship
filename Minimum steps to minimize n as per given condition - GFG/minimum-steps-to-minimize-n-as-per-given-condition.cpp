//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    
	    vector<int> dp(N+1);
	    dp[1] = 0;
	    if(N>1) dp[2] = 1;
	    
	    int x=3;
	    
	    while(x<=N)
	    {
	        if(x%2==0 && x%3==0)
	        {
	            dp[x] = min(dp[x-1]+1, min(dp[x/2]+1, dp[x/3]+1));
	        }
	        else if(x%2==0)
	        {
	            dp[x] = min(dp[x-1]+1, dp[x/2]+1);
	        }
	        else if(x%3==0)
	        {
	            dp[x] = min(dp[x-1]+1, dp[x/3]+1);
	        }
	        else
	          dp[x] = dp[x-1] + 1;
	          
	          x++;
	    }
	    
	    return dp[N];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends