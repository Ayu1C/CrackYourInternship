class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        map<int, int> mp;
        int duplicate, missing;
        
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2) duplicate = nums[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(mp[i]==0) missing = i;
        }
        
        return {duplicate, missing};
    }
};