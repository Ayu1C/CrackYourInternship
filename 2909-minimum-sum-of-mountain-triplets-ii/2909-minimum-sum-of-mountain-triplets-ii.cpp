class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size(), sum = INT_MAX;
        vector<int> prefix_min(n, 0), suffix_min(n,0);
        
        prefix_min[0] = nums[0], suffix_min[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++)
        {
           prefix_min[i] = min(nums[i], prefix_min[i-1]);
        }
        
        for(int j=n-2; j>=0; j--)
        {
           suffix_min[j] = min(suffix_min[j+1], nums[j]); 
        }
        
        for(int i=0; i<n; i++)
        {
           if(prefix_min[i] != nums[i] && suffix_min[i] != nums[i])
           {
               sum = min(sum, (nums[i]+prefix_min[i]+suffix_min[i]));
           }
        }
        
        if(sum==INT_MAX) return -1;
        
        return sum;
    }
};