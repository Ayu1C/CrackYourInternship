class Solution {
public:
    int partitionString(string s) {
        
        int part = 1;
        
        int i=0;
        map<char, int> mp;
        
        while(i<s.length())
        {
            mp[s[i]]++;
            if(mp[s[i]] > 1)
            {
                part++;
                mp.clear();
            }
            else i++;
        }
        return part;
    }
};