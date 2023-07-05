class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int ans;
        for(int i=0; i<nums.size(); i++)
        {
           if(m.find(nums[i]) != m.end())
           {
               m[nums[i]]++;
           }
            else
            {
                m.insert(std::pair<int,int>(nums[i],1));
            }
        }
        
        for(auto &i : m)
        {
            if((i.second) > nums.size()/2)
                ans = i.first;
        }
        return ans;
    }
};