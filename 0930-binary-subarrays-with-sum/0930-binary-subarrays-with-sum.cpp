class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int, int> mp;
        int s = 0, ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            s += nums[i];
            if(s==goal) 
            {
                ans++;
                if(mp.find(s-goal) != mp.end())
                {
                   ans += mp[s-goal]; 
                }
            }
            else if(s > goal)
            {
                if(mp.find(s-goal) != mp.end())
                {
                   ans += mp[s-goal]; 
                }
            }
            mp[s]++;
        }
        
        return ans;
    }
};