class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int l = s.length(), count = 0;
        
        for(int i=0; i<l; i++)
        {
            if(s[i]=='1') count++;
            
            s[i] = '0';
        }
        
        s[l-1] = '1';
        
        count--;
        int idx = 0;
        
        for(int i=0; i<count; i++)
        {
           s[idx] = '1';
            idx++;
        }
        
         return s;
    }
};