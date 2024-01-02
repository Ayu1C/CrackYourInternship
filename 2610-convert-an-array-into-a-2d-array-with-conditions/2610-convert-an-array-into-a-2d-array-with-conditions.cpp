class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vector<vector<int>> res;
        map<int, int> count;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(!count.empty() && count.find(nums[i]) != count.end())
            {
                count[nums[i]]++;
            } else{
                count[nums[i]] = 1;
            }
        }
        
        bool rem = 1;
        
        while(rem)
        {
            vector<int> temp;
            for(auto &it : count)
            {
                if(it.second > 0)
                {
                    temp.push_back(it.first);
                    it.second -= 1;
                } 
            }
            if(temp.empty()) rem = 0;
            else res.push_back(temp);
        }
        
        return res;
    }
};