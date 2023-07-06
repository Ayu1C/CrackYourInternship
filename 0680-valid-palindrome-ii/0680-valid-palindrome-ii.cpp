class Solution {
public:
    
    bool checkPalindrome(int l, int r, string &s)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
              return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int beg = 0, end = s.length()-1;
        while(beg < end)
        {
            if(s[beg]==s[end])
            {
                beg++;
                end--;
            }
            else return(checkPalindrome(beg+1, end, s) || checkPalindrome(beg, end-1, s));
              
        }
        return true;
    }
};