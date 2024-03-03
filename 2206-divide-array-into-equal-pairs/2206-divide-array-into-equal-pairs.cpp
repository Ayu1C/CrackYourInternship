class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        map<int, int> count;
        
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        
        for(auto it : count)
        {
            if(it.second % 2 != 0) return false;
        }
        
        return true;
    }
};