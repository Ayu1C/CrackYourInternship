class Solution {
public:
    
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        
        int i=0, j=-1, cur=0, maxc=0;
        
        while(k--)
        {
            j++;
            if(isVowel(s[j])) cur++;
        }
        
        maxc = max(maxc, cur);
        
        while(j<s.length())
        {
            if(isVowel(s[i])) cur--;
            i++;
            j++;
            
            if(j<s.length() && isVowel(s[j])) cur++;
            
            maxc = max(maxc, cur);
        }
        
        return maxc;
    }
};