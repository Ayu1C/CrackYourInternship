class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int i=0, j=0, maxl = 0, cur = 0;
       
        while(j<s.length())
        {
            cur += abs(s[j]-t[j]);
            
            if(cur > maxCost)
            {
                while(cur > maxCost)
                {
                   cur -= abs(s[i] - t[i]);
                   i++;
                }
                maxl = max(maxl, j-i+1);
            }
            else
            {
                maxl = max(maxl, j-i+1);
            }
            
            j++;
        }
        
        return maxl;
        
    }
};