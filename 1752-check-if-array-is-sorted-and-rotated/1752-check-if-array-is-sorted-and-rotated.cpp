class Solution {
public:
    bool isSorted(vector<int>& nums, int start, int end){
        for(int i=start+1; i<=end; i++){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    
    bool check(vector<int>& nums) {
       int n = nums.size();
        
        if(nums[0] < nums[n-1] ) {
           if(isSorted(nums, 0, n-1)) return true;
           else return false;
        }
        else {
           int point;
           for(int i=1; i<n; i++){
               if(nums[i] < nums [i-1]){
                  point = i;
                  break;
               }
           }
           if(isSorted(nums, point, n-1)) return true;
           return false;
        }
        return false;
    }
};