class Solution {
public:
    int minimumLength(string s) {
     
        int n = s.length(), i = 0, j = n-1, ans = n;
        
        while(i<j)
        {
            if(s[i] != s[j])
            {
                ans = j-i+1;
                break;
            }
            else
            {
                char del = s[i];
                
                while(s[i] == del)
                {
                   i++;
                    if(i==j) return 0;
                }
                while(s[j]==del)
                {
                    j--;
                }
            }
        }
        
        if(i==j) return 1;
        
        if(i>j) return 0;
        
        return ans;
    }
};