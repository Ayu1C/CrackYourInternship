class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size()==1) return;
        if(nums.size()==2 && nums[0]==0) return;
        int low = 0, high = nums.size()-1, mid = 0;
        
        while(mid<=high)
        {
           if(nums[mid]==0)
           {
              swap(nums[mid], nums[low]);
               low++; mid++;
           }
           else if(nums[mid]==1) mid++;
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};