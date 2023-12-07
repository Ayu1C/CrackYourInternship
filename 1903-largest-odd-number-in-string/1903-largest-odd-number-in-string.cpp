//#include <boost/multiprecision/cpp_int.hpp>

class Solution {
public:
    string largestOddNumber(string num) {
        
//         unsigned long long ans = INT_MIN;
//         unsigned long long n = stoull(num);
        
//         while(n)
//         {
//            if(n % 2 == 1 && n > ans) ans = n;
//             n /= 10;
//         }
        
//         if(ans == INT_MIN) return "";
//         else return to_string(ans);
        
        int n = num.length();
        
        for(int i = n-1; i>=0; i--)
        {
            if(num[i] % 2 == 1) return num.substr(0, i+1);
        }
        
        return "";
    }
};