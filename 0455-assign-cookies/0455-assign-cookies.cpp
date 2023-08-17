class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int p1 = 0, p2 = 0;
        
        while(p1 < g.size() && p2 < s.size())
        {
            if(s[p2]>=g[p1])
            {
                ans++;
                p2++;
                p1++;
            }
            else if(s[p2]<g[p1])
            {
                p2++;
            }
        }
        return ans;
    }
};