//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

private:
    bool isNegCycle(int node, int n, vector<vector<int>>edges, vector<int>& dist)
    {
        dist[node] = 0;
       int i=n-1;
        while(i--)
        {
            for(auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != 1e8)
                {
                    if(dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        
        for(auto it : edges)
        {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != 1e8)
                {
                    if(dist[u] + w < dist[v])
                    {
                        return 1;
                    }
                } 
        }
        
        return 0;
         
    }
    
 public:   
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	     vector<int> dist(n, 1e8);
        dist[0] = 0;
        
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            // If cycle found
            if (isNegCycle(i, n, edges, dist))
                return true;
 
            // Mark all vertices that are visited
            // in above call.
            for (int i = 0; i < n; i++)
                if (dist[i] != 1e8)
                    visited[i] = true;
        }
    }
 
       return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends