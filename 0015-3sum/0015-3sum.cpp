class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        //vector to hold temporary triplet
        vector<int> temp;
        
    //sorting to remove or ignore duplicates easily
      sort(nums.begin(), nums.end());
     
        // So, the approach we will follow will be that we'll take one element from start and for it, we will try to search for corresponding 2 elements, whose sum when added to the number we took, gives 0.
        
        //while selecting numbers we will keep in mind to ignore duplicate values while iterating
        
       for(int i=0; i<nums.size()-2; i++)
       {
           if(i==0 || (i>0 && nums[i-1]!=nums[i]))
           {
               int low = i+1;
               int high = nums.size()-1;
               int target = 0 - nums[i];
               
               while(low<high)
               {
                  if(nums[low]+nums[high]==target)
                   {
                       temp.push_back(nums[low]);
                       temp.push_back(nums[high]);
                       temp.push_back(nums[i]);
                       ans.push_back(temp);
                       temp.clear();
                      
                      while(low<high && nums[low]==nums[low+1])low++;
                      while(low<high && nums[high]==nums[high-1])high--;
                    
                      low++;
                      high--;
                   }
                   
                   else if(nums[low]+nums[high]<target)
                   {
                     low++;
                   }
                   
                   else
                   {
                       high--;
                   }
                 
               }
               
               
               
            }
       }
        return ans;
        
    }
};