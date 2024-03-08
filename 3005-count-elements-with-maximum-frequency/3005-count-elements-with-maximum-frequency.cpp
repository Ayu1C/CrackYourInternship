class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        map<int, int> mp;
        int maxC = 0, ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > maxC) maxC = mp[nums[i]];
        }
        
        for(auto it : mp)
        {
            if(it.second==maxC) ans += it.second;
        }
        
        return ans;
    }
};