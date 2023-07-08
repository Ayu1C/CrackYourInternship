class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        //edge case - any integer to the power 0 equals 1
        if(n==1) return true;
        if(n==0) return false;
        
        while(n!=1)
        {
            if(n%2 != 0 ) return false; 
            n /= 2;
        }
        return true;
    }
};