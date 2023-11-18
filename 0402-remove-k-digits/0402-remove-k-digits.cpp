class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();
        
        if(n==k) return "0";
        
        stack<int> s;
        
        int req = n-k;
        
        s.push(num[0]);
        
        for(int i=1; i<n; i++)
        {
            while(!s.empty() && num[i]<s.top() && s.size()+n-i>req )
            {
                s.pop();
            }
            s.push(num[i]);
        }
        
        string res = "";
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
        string ans = res.substr(0,req);
        
        ans.erase(0, min(ans.find_first_not_of('0'), ans.length()-1));
        
        if(ans=="") return "0";
        
        return ans;
        
    }
};