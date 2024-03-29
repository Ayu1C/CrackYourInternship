class Solution {
public:
   
    int maxProd = 1, n;
    bool isPalindrome(const string& s)
    {
        int n = s.size();
        for(int i=0; i<n/2; i++)
            if(s[i] != s[n-1-i]) return false;
        return true;
    }
    
    void solve(string& s, string& first, string& second, int idx)
    {
        if(idx == n) 
        {
			// Check if both strings are palindrome or not
			// If yes, then find product or their lengths
            if(isPalindrome(first) && isPalindrome(second))         
            {
                maxProd = max(maxProd, (int)(first.size() * second.size()));
            }
            return;
        }
        
        // Choice 1 : Exclude current element from both strings
        solve(s, first, second, idx+1);
        
        // Choice 2 : Include current element into first string
        first.push_back(s[idx]);
        solve(s, first, second, idx+1);
        first.pop_back();
        
        // Choice 3 : Include current element into second string
        second.push_back(s[idx]);
        solve(s, first, second, idx+1);
        second.pop_back();
    }
    
    int maxProduct(string s) {
        n = s.size();
        string first = "", second = "";
        solve(s, first, second, 0);                              // Start from 0th index
        return maxProd;
    }
};