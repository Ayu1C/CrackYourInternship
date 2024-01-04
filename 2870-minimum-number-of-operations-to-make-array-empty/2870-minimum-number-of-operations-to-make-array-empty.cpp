class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                mp[nums[i]]++;
            }
            else {
                mp[nums[i]] = 1;
            }
        }
        
        int operations = 0;
        
        for(auto &it : mp)
        {
            int c = it.second;
            
            if(c/3==0)
            {
                if(c%3==1) return -1;
                else operations += 1;
            } else if(c/3 > 0)
            {
                operations += c/3;
                
                if(c%3 != 0) operations += 1;
            }
        }
        
        return operations;
    }
};