class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        
        sort(citations.begin(), citations.end());
        
        if(citations[n-1]==0) return 0;
        
        vector<int> count(n,1);
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(citations[j]>=citations[i]) 
                {
                    count[i]+=n-j;
                    break;
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(count[i]<=citations[i]) ans = max(ans, count[i]);
        }
        
        return ans;
    }
};