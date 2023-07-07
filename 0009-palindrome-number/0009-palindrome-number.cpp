class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0) return false;
        
        else
        {
            long temp = x, rev=0;
            while(temp != 0)
            {
                rev = (rev*10) + (temp%10);
                temp /= 10;
            }
            if(rev == x)return true;
            else return false;
        }
    
        
    }
};