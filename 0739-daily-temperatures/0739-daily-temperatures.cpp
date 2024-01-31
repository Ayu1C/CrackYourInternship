class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper) {
        
        int n = temper.size();
        vector<int> temp(n, -1), ans(n, 0);
        
        ans[n-1] = 0;
        
        for(int i=n-2; i>=0; i--)
        {
            if(temper[i+1] > temper[i])
            {
                ans[i] = 1;
                temp[i] = temper[i+1];
            }
            else 
            {
                if(ans[i+1]==0)
                {
                    ans[i] = 0;
                }
                else if(temp[i+1] != -1 && temp[i+1] > temper[i])
                {
                    ans[i] = 1+ans[i+1];
                    temp[i] = temp[i+1];
                }
                else
                {
                    int idx = i+2;
                    while(idx<n)
                    {
                        if(temper[idx] > temper[i])
                        {
                            ans[i] = idx-i;
                            temp[i] = temper[idx];
                            break;
                        }
                        idx++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};