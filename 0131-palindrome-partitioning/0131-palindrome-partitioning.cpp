class Solution {
public:
    
    bool palindrome(string& s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    void f(int index, vector<string>& part, vector<vector<string>>& res, string& s)
    {
       if(index==s.length())
       {
           res.push_back(part);
           return;
       }
        
        for(int i=index; i<s.length(); i++)
        {
            if(palindrome(s, index, i))
            {
                part.push_back(s.substr(index, i-index+1));
                f(i+1, part, res, s);
                part.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
       
        vector<vector<string>> res;
        vector<string> part;
        
        f(0, part, res, s);
        
        return res;
    }
};