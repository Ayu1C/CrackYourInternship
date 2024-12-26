class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        //Moore's Voting algorithm
        int n = nums.size();
        int ele, count = 0;
        
        for(int i=0; i<n; i++) {
            if(count == 0){
                ele = nums[i];
                count++;
            }
            else if(ele == nums[i]) count++;
            else count--;
        }
        
        return ele;
    }
};