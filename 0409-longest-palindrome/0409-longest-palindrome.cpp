class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char, int> count;
        
        for(int i=0; i<s.length(); i++)
        {
            count[s[i]]++;
        }
        
        int ans = 0;
        bool centre_taken = false, found_odd = false;
        
        for(auto& it : count)
        {
            if(it.second > 1) 
            {
                if(it.second % 2 != 0)
                {
                    ans += it.second - 1;
                    found_odd = true;
                }
                else ans += it.second;
            }
            
            else if(it.second == 1)
            {
                if(centre_taken == false)
                {
                    ans += 1;
                    centre_taken = true;
                }
            }
        }
        
        if(centre_taken == false && found_odd == true) ans += 1;
        
        return ans;
    }
};