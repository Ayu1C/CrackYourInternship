class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0) count++;
        }
        
        if(count==nums.size()) return;
            
        int p1 = 0, p2=0;
      
        while(p1 <= nums.size()-1-count)
        {
           if(nums[p2] != 0)
           {
             nums[p1] = nums[p2];
               p1++;
               p2++;
           }
            else
            {
               p2++;
            }
        }
        
        for(int i=nums.size()-count; i<nums.size(); i++)
        {
            nums[i] = 0;
        }
        
    }
};