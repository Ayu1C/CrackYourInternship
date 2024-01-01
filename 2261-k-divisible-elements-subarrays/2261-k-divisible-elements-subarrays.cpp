class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n = nums.size();
        
        set<vector<int>> subarrays;
        
        for(int i=0; i<n; i++)
        {
               int div_c = 0;
               vector<int> temp_sub;
            
            for(int j=i; j<n; j++)
            {
                 temp_sub.push_back(nums[j]);
                 if(nums[j] % p == 0) div_c++;
                
                if(div_c <= k) subarrays.insert(temp_sub);
            }
        }
        
        return subarrays.size();
    }
};