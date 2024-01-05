class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size(), max1 = 0, cur_count = 0, i=0, j;
        
        while(i<n)
        {
            if(nums[i]==1)
            {
                cur_count++;
                {
                    for(j=i+1; j<n; j++)
                    {
                        if(nums[j]==1) cur_count++;
                        else
                        {
                            max1 = max(max1, cur_count);
                            cur_count = 0;
                            i = j;
                            break;
                        }
                    }
                    if(j==n)
                    {
                        max1 = max(max1, cur_count);
                        break;
                    }     
                }
            }
            i++;
        }
        
        return max1;
    }
};