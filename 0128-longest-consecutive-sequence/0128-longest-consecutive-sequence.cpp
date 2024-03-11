class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        set<int> all;
        int ans = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            all.insert(nums[i]);
        }
        
        for(int x : all)
        {
            if(all.find(x-1) != all.end()) continue;
            
            int curr = x;
            int y = x;
            
            while(all.find(curr+1) != all.end())
            {
                y++;
                curr++;
            }
            
            ans = max(ans, y-x+1);
        }
        
        return ans;
    }
};