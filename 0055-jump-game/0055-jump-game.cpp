class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxReach = 0;
        
        for(int i=0; i<n-1; i++)
        {
            if(i>maxReach) return false;
            
            if(nums[i]==0 && maxReach <=i) return false;
            maxReach = max(i+nums[i], maxReach);
            
        }
        return true;
    }
};