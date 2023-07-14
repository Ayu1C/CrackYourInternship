class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans;
        vector<int> nums;
        int p1 = 0, p2 = 0;
        
        while(p1<nums1.size() && p2<nums2.size())
        {
            if(nums1[p1]<=nums2[p2])
            {
                nums.push_back(nums1[p1]);
                p1++; 
            }
            else if(nums1[p1] > nums2[p2])
            {
                nums.push_back(nums2[p2]);
                p2++;
            }
        }
        if(p1<nums1.size())
        {
            while(p1<nums1.size())
            {
                nums.push_back(nums1[p1]);
                p1++;
            }
        }
        if(p2<nums2.size())
        {
            while(p2<nums2.size())
            {
                nums.push_back(nums2[p2]);
                p2++;
            }
        }
        
        int n = nums.size(), temp;
        if(n%2==0)
        {
            temp = (nums[(n/2)-1] + nums[n/2]);
            ans = (double)temp / 2;
        }
        else ans = nums[n/2];
        
        return ans;
            
    }
};