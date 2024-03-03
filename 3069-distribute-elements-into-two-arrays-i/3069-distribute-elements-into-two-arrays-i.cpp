class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> arr1, arr2;
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        int i=2;
        
        while(i<nums.size())
        {
            arr1[arr1.size()-1] > arr2[arr2.size()-1] ? arr1.push_back(nums[i]) : arr2.push_back(nums[i]);
            i++;
        }
        
        arr2.insert(arr2.begin(), arr1.begin(), arr1.end());
        
        return arr2;
    }
};