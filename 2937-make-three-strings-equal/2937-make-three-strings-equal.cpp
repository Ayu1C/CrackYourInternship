class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        
        int count = 0;
        
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        int n = min(n1, min(n2,n3));
        
        while(count<n && s1[count]==s2[count] && s2[count]==s3[count])
            count++;
        
        if(count==0) return -1;
        
        return n1+n2+n3-3*count;
    }
};