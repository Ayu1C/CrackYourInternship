class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return;
        
        sort(nums.begin(), nums.end(), greater <>());
        //int median = n/2;
        
//         vector<int> part1, part2;
        
//         for(int i=0; i<=n/2; i++)
//         {
//             part1.push_back(nums[i]);
//         }
//         for(int i=n/2+1; i<n; i++)
//         {
//             part2.push_back(nums[i]);
//         }
        
//         int i=0, j=0;
//         while(i<n && j<part1.size() && j<part2.size())
//         {
//             nums[i] = part1[j];
//             nums[i+1] = part2[j];
//             j++;
//             i+=2;
//         }
        
//         if(i<n)
//         {
//             if(j<part1.size())
//             {
//                 while(i<n)
//                   nums[i++] = part1[j++];
//             }
//             else if(j<part2.size())
//             {
//                 while(i<n)
//                   nums[i++] = part2[j++];
//             }
//         }
        
        vector<int> ans(n,0);
        
        int i=1, j=0, count=2;
        
        while(count)
        {
            while(i<n && j<n)
            {
                ans[i] = nums[j];
                j++;
                i += 2;
            }
            count--;
            i=0;
        }
        
        for(int i=0; i<n; i++)
        {
            nums[i] = ans[i];
        }
    }
};