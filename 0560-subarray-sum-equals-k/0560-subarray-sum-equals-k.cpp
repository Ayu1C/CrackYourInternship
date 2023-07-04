class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        
        map<int, int> sum;
        
        int curSum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
           curSum += nums[i];
            
            if(curSum == k) count++;
            
            if(sum.find(curSum - k)!=sum.end())
            {
                 count += sum[curSum - k];
            }
            
            sum[curSum]++;
        }
        return count;
    }
};