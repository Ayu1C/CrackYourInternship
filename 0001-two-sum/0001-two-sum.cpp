class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> v, ans;
        
        bool found = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            v.push_back(target - nums[i]);
            for(int j=0; j<v.size(); j++)
            {
               if(v[j]==nums[i] && i!=j)
               {
                   ans.push_back(i);
                   ans.push_back(j);
                   found = 1;
                   break;
               }
            }
            if(found == 1) break;
        }
        
        return ans;
    }
};

//A more optimized approach using hash table (i.e. unordered map)

// vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;
       
//         for(int i = 0; i < nums.size(); i++){
//             if(mp.find(target - nums[i]) == mp.end())
//                 mp[nums[i]] = i;
//             else
//                 return {mp[target - nums[i]], i};
//         }
 
//         return {-1, -1};
// }