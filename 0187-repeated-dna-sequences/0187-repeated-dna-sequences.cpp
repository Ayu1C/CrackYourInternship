class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n = s.length();
        map<string, int> mp;
        
        vector<string> res;
        
        if(n<10) return res;
        
        for(int i=0; i<n-9; i++)
        {
            mp[s.substr(i,10)]++;
        }
        
        for(auto& it : mp)
        {
            if(it.second > 1)
                res.push_back(it.first);
        }
        
        return res;
    }
};