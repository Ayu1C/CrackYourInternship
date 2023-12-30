class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        map<char, int> mp;
        
        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                if(mp.find(words[i][j]) != mp.end()) mp[words[i][j]]++;
                else mp[words[i][j]] = 1;
            }
        }
        
        for(auto it : mp)
        {
            if(it.second % words.size() != 0) return false;
        }
        
        return true;
    }
};