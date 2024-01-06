class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size(), median;
        sort(nums.begin(), nums.end());
        
        median = nums[n/2];
        
        int diff = 0;
        
        for(int i=0; i<n; i++)
        {
            diff += abs(nums[i]-median);
        }
        
        return diff;
    }
};