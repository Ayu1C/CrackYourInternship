class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        vector<int> count(nums.size(),0);
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        for(int i=1; i<nums.size(); i++)
        {
            if(count[i]>=2) 
            {
              ans = i;
              break;
            }
        }
        return ans;
    }
};