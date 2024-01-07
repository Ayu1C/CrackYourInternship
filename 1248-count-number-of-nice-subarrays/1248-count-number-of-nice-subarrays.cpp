class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int c = 0, n=nums.size();
        
        vector<int> prefix(n, 0);
        map<int, int> sum;
        
        prefix[0] = nums[0] % 2 == 0 ? 0 : 1;
        nums[0] = nums[0] % 2 == 0 ? 0 : 1;
        sum[prefix[0]]++;
        if(nums[0]==1 && k==1) c++;
            
        for(int i=1; i<n; i++)
        {
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
            
            prefix[i] = prefix[i-1] + nums[i];
            sum[prefix[i]]++;
            
            if(prefix[i]==k) c++;
            
            if(sum.find(prefix[i]-k) != sum.end())
            {
                c += sum[prefix[i]-k];
                //sum[prefix[i]-k]--;
            }
           
        }
        

        return c;
    }
};