class Solution {
public:
    int mySqrt(int x) {
        
//         long ans;
//         for(long i=0; i<=x; i++)
//         {
//             if(i*i <= x)
//                 ans = i;
//             else if(i*i > x)
//                 break;
//         }
        
//         return (int)ans;
        
        long ans = 0;
        long l = 0, h = x;
        while(l<=h)
        {
           long mid = l + (h-l)/2;
            if(mid*mid == x)
            {
                ans = mid;
                break;
            }
            else if(mid*mid < x)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        
        return (int)ans;
    }
};