class Solution {
public:
    string lastNonEmptyString(string s) {
        
        map<char, int> mp;
        
        int n = s.length(), max_c = 0;
        string ans = "";
        
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
            if(mp[s[i]] > max_c) max_c = mp[s[i]];
        }
        
        map<char, int> rem;
        for(auto it : mp)
        {
           if(it.second == max_c) rem[it.first] = it.second;
        }
        
        for(int i=0; i<n; i++)
        {
            if(rem[s[i]] > 1) rem[s[i]]--;
            else if(rem[s[i]]==1) ans += s[i];
        }
        
        return ans;
    }
};