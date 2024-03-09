class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
//         int ans, n1 = nums1.size(), n2 = nums2.size(), i=0, j=0;
        
//         while(i<n1 && j<n2)
//         {
//             if(nums1[i]==nums2[j])
//             {
//                ans = nums1[i];
//                 break;
//             }
//             else if(nums1[i] < nums2[j])
//             {
//                 while(nums1[i] < nums2[j])
//                     i++;
//             }
//             else
//             {
//                while(nums2[j] < nums1[i])
//                     j++; 
//             }
//         }
            
//         return ans;
        
        map<int, int> mp1, mp2;
        
        for(int i=0; i<nums1.size(); i++)
        {
            mp1[nums1[i]]++;
        }
        for(int j=0; j<nums2.size(); j++)
        {
            mp2[nums2[j]]++;
        }
        
        for(auto it : mp1)
        {
            if(mp2.find(it.first) != mp2.end() && mp2[it.first]>=1)
            {
                return it.first;
            }
        }
        
        return -1;
    }
};