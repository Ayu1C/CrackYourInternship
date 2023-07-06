class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
//         we find out, that a subarray may also exist if this particular condition satisified, i.e
//     (prefix[i] - k) should exist in our map, 
	
// 	How? see,
	
// 	If prefix[i] - prefix[j] = k where i > j (i, j any index, in our case they are i = 3, j = 0)
// 	prefix[i] - k = prefix[j] na, (simple maths)
	
// 	i.e if we are able to find (prefix[i] - k) is exist in our map, i.e prefix[j]
// 	so, we can say that from index j + 1 to i, the sum of the elements is k, right na,
// 	hence it proves that their exist an subarray from index j + 1 to i whose sum is k.
        
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