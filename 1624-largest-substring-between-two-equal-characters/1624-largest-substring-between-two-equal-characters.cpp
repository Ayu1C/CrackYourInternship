class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        map<char, pair<int, int>> mp;
        int maxDiff = 0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(mp.find(s[i]) == mp.end())
               mp[s[i]] = {i,0};
            else{
                mp[s[i]].second = i;
                maxDiff = max(maxDiff, mp[s[i]].second - mp[s[i]].first);
            }
        }
       
         return maxDiff - 1;    
    }
};