class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        
        int a=0, b=1;
        
        while(b <= n-2)
        {
           for(int c=b+1; c<n; c++)
           {
               if(nums[a] + nums[b] > nums[c])
               {
                   ans = max(ans, nums[a] + nums[b] + nums[c]);
               }
           }
        
            a++;
            b++;
        }
        
        return ans;
    }
};