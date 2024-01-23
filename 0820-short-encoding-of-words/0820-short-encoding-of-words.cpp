class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        set<string> unique;
        
        for(int i=0; i<words.size(); i++)
        {
            unique.insert(words[i]);
        }
        
        for(auto& it : unique)
        {
            for(int j=1; j<it.length(); j++)
            {
                unique.erase(it.substr(j));
            }
        }
        
        int ans = 0;
        for(auto& it : unique)
        {
            ans += it.length() + 1;
        }
        
        return ans;
    }
};