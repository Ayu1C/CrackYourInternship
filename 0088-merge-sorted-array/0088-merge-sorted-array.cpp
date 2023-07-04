class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        //Merge two sorted arrays without using any extra space
        
        //One approach is to copy the elements fron num2 into remaining space in num1. Then    sort num1 and return num1.
        
//         for(int i=0; i<n; i++)
//         {
//            nums1[m+i] = nums2[i];
//         }
//         sort(nums1.begin(), nums1.end());
        
        //Below is optimized two pointers approach
        
        
        if(m==0)
        {
           for(int i=0; i<n; i++)
           {
               nums1[i] = nums2[i];
           }
            return;
        }
        
        int p1=m-1, p2=n-1, k=m+n-1;
        
        while(p1>=0 && p2>=0)
        {
            if(nums1[p1]>=nums2[p2])
            {
               nums1[k]=nums1[p1];
                p1--;
                k--;
            }
            
            else if(nums1[p1]<nums2[p2])
            {
                nums1[k] = nums2[p2];
                p2--;
                k--;
            }   
        }
        if(p2 >= 0)
        {
            for(int i=k; i>=0; i--)
            {
               nums1[i] = nums2[p2];
                p2--;
            }
        }
        
    }
};