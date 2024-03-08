class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        vector<pair<char, char>> diff;
        
        int i=0;
        
        while(i<s1.length())
        {
            if(s1[i] != s2[i])
            {
                diff.push_back(make_pair(s1[i], s2[i]));
            }
            i++;
        }
        
        if(diff.size() == 0) return true;
        
        if(diff.size() != 2) return false;
        
        if(diff[0].first == diff[1].second && diff[0].second == diff[1].first) return true;
        else return false;
    }
};