class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum = 0;
        for(auto i: nums) sum += i;
        
        int minNum = *min_element(nums.begin(), nums.end());
        
        return sum - nums.size()*minNum;
    }
};