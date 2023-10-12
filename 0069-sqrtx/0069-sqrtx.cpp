class Solution {
public:
    int mySqrt(int x) {
        
        long ans;
        for(long i=0; i<=x; i++)
        {
            if(i*i <= x)
                ans = i;
            else if(i*i > x)
                break;
        }
        
        return (int)ans;
    }
};