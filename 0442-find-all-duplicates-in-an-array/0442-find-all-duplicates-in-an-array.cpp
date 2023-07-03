class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans, count(nums.size()+1,0);
        
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        for(int i=1; i<count.size(); i++)
        {
            if(count[i]==2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};