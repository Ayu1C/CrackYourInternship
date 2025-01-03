class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       
        int max1 = 0, cur1 = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                max1 = max(max1, cur1);
                cur1 = 0;
            } else
                cur1 += 1;
        }
        
        max1 = max(max1, cur1);
        return max1;
    }
};