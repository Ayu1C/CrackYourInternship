class Solution {
public:
    int reverse(int x) {
        
        int temp = x;
        x = abs(x);
        long long ans = 0;
        
        while(x != 0)
        {
            ans = ans*10 + (x%10);
            x /= 10;
        }
         if(temp<0) ans = 0-ans;
        
        if(ans>= pow(-2,31)&& ans <= pow(2,31)-1)return ans;
        else return 0;
    }
};