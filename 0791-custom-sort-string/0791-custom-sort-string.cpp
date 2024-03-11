class Solution {
public:
    string customSortString(string order, string s) {
        
        string ans = "";
        
        map<char, int> mp;
        
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0; i<order.length(); i++)
        {
            if(mp.find(order[i]) != mp.end())
            {
                int t = mp[order[i]];
                while(t--) ans += order[i];
                mp.erase(order[i]);
            }
        }
        
        for(auto it : mp)
        {
            int t = it.second;
            while(t--) ans += it.first;
        }
        
        return ans;    
    }
};