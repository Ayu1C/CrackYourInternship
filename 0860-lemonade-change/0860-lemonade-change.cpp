class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n5 = 0, n10 = 0, n20 = 0;
        
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==5)
            {
               n5++;
            }
            else if(bills[i]==10)
            {
                n10++;
                if(n5!=0)
                {
                    n5--;
                }
                else return false;
            }
            else
            {
                n20++;
                if(n5==0 || (n10==0 && n5<=2)) return false;
                else 
                {
                    if(n10)
                    {
                        n10--, n5--;
                    }
                    else n5 -= 3;
                }
            }
            
        }
        
        return true;
    }
};