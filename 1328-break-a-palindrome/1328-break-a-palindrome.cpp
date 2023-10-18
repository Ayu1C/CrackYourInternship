class Solution {
public:
    
    bool isPalindrome(string s)
    {
        int i=0, j=s.length()-1;
        
        while(i <= j)
        {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.length(), i;
        
        if(n==1) return "";
        
        for(i=0; i<n; i++)
        {
            if(palindrome[i]!='a')
            {
                char temp = palindrome[i];
                palindrome[i] = 'a';
                if(isPalindrome(palindrome)==false)
                  break;
                else palindrome[i] = temp;
            }
        }
        
        if(i==n)
            palindrome[n-1] = 'b';
        
        
        return palindrome;
    }
};