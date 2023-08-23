class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int count = 0;
        map<int, int> sum;
        
        int curSum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
           curSum += nums[i];
            
            if(curSum == goal) count++;
            
            if(sum.find(curSum - goal)!=sum.end())
            {
                 count += sum[curSum - goal];
            }
            
            sum[curSum]++;
        }
        return count;
    }
};