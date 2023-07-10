class Solution {
public:
    
    void combinations(int open, int close, vector<string> &ans, string str)
    {
        if(open==0 && close==0)
        {
            ans.push_back(str);
            return;
        }
        
        if(open > 0) //will cover condition of open==close 
        {
           combinations(open-1, close, ans, str+"(");
        }
        if(close > 0 && close>open) 
        {
           combinations(open, close-1, ans, str+")");
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        
        combinations(n, n, ans, "");
        
        return ans;
        
    }
};