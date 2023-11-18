class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       
        int n = numbers.size();
        vector<int> ans(2,0);
        
        int low, high, mid;
        
      for(int i=0; i<n-1; i++)
      {
          int rem = target-numbers[i];
         low = i+1, high = n-1;
          while(low<=high)
          {
              mid=low+(high-low)/2;
              if(numbers[mid]==rem)
              {
                  ans[0]=i+1, ans[1]=mid+1;
                  break;
              }
              else if(numbers[mid]>rem) high=mid-1;
              else low = mid+1;
          }
          if(ans[0]!=0) break;
      }
        
        return ans;
    }
};