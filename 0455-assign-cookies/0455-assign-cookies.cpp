class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int gi = 0, si = 0, content = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(gi < g.size() && si < s.size())
        {
            if(s[si] >= g[gi]){
                content++;
                si++;
                gi++;
            } else if(s[si] < g[gi]){
               si++;
            }
        }
        
        return content;
    }
};