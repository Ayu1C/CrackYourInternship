class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < k) ans++;
        }
        
        int i=0, j;
        
        while(i<nums.size()-1)
        {
            j = i+1;
            int prod = nums[i];
            
            while(j<nums.size())
            {
                prod *= nums[j];
                if(prod < k) ans++;
                else break;
                
                j++;
            }
            
            i++;
        }
        
        return ans;
    }
};