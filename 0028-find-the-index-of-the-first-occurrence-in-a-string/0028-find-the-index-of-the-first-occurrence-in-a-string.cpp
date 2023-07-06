class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.length()>haystack.length()) return -1;
        
        int firstocc = -1;
        for(int i=0; i<=haystack.size()-needle.size(); i++)
        {
            if(haystack[i]==needle[0])
            {
                firstocc = i;
                for(int j=1; j<needle.size(); j++)
                {
                    if(needle[j]!=haystack[i+j])
                    {
                        firstocc = -1;
                        break;
                    }
                }
                if(firstocc != -1) break;
            }
        }
        return firstocc;
    }
};