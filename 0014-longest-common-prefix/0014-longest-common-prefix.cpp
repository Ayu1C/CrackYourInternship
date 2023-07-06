class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        int idx = 0;
        
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        
        while(idx < s1.size() && idx < s2.size())
        {
            if(s1[idx]==s2[idx]) idx++;
            else break;
        }
        return s1.substr(0,idx);
    }
};