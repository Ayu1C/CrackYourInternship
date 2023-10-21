class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count=0, n=s.length();
        bool flag = 0;
        
        for(int i=n-1; i>=0; i--){
            
            if(s[i]==' ' && flag) break;
            else if(s[i]!=' ')
            {
                flag = 1;
                count++;
            }
        }
        return count;
    }
};