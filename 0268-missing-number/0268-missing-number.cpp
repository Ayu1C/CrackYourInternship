class Solution {
public:
    int missingNumber(vector<int>& nums) {
       
        int n = nums.size();
        int sum_of_n_num = (n*(n+1))/2, actual_sum = 0;
        
        for(int i=0; i<n; i++){
            actual_sum += nums[i];
        }
        
        return sum_of_n_num - actual_sum;
    }
};