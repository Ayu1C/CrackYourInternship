class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& temp, vector<int>& nums, int start){
        ans.push_back(temp);
        for(int i=start; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
            backtrack(temp, nums, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(temp, nums, 0);
        return ans;
    }
};