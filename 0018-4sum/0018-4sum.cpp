class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n=nums.size();
        
        set<vector<int>> s;
        vector<vector<int>> v;
        
        if(n<4)
        {
           return v;
        }
        
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int first=j+1, last=n-1;
                long long rem = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(first<last)
                {
                    if(nums[first]+nums[last] < rem)
                    {
                        first++;
                    }
                    else if((nums[first] + nums[last]) > rem)
                    {
                        last--;
                    }
                    else
                    {
                        s.insert({nums[i],nums[j],nums[first],nums[last]});
                        first++;
                        last--;
                    }
                }
               
            }
            
        }
        
        for(auto i : s)
        {
            v.push_back(i);
        }
        return v;
        
    }
};