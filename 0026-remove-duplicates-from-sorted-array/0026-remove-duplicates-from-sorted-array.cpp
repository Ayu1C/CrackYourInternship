class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=1;
        
       for(int k=1; k<nums.size(); k++){
           if(nums[k] != nums[k-1]){
               nums[i] = nums[k];
               i++;
           }
       }
        
        return i;
    }
};