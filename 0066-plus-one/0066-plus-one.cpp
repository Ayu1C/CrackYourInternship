class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = digits[n-1] + 1;
        if(i<10)
        {
            digits[n-1] = i;
        }
        else
        {
            if(digits.size()==1)
            {
                digits[0]=0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
               digits[n-1] = i%10;
                int carry = i/10;
                int prev = n-2;
                while(prev>=0 && carry)
                {
                    carry += digits[prev];
                    digits[prev] = carry % 10;
                    carry /= 10;
                    prev--;
                }
               
                if(carry != 0)
                {
                    digits.insert(digits.begin(), 1);
                }
            }
            
        }
        return digits;
    }
};