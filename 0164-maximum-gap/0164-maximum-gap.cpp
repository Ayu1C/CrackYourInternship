class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 2) return 0;
        
        sort(nums.begin(), nums.end());
    
        int max_diff = INT_MIN;
        
        for(int i=1; i<n; i++)
        {
            int diff = abs(nums[i] - nums[i-1]);
           if(diff > max_diff) 
               max_diff = diff;
        }
     
        return max_diff;
    }
};