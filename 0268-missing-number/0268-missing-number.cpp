class Solution {
public:
    int missingNumber(vector<int>& nums) {
       
        vector<int> count(nums.size()+1, 0);
        int ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        
        for(int i=0; i<count.size(); i++)
        {
            if(count[i]==0)
            {
               ans = i;
                break;
            }
        }
        return ans;
    }
};