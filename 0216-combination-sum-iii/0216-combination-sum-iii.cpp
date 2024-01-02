class Solution {
    
private:
    set<vector<int>> res;
    
public:
    void backtrack(vector<int> temp, vector<int>& nums, int k, int remain, int start)
    {
       if(remain < 0 || k < 0) return;
       else if(remain==0 && k==0) res.insert(temp);
        //else if(8 - start < k) return;
        else{
            
            for(int i=start; i<nums.size(); i++)
            {
                temp.push_back(nums[i]);
                backtrack(temp, nums, k-1, remain-nums[i], i+1);
                temp.pop_back();
            }
        }
    }
        
           
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> nums;
        for(int i=1; i<=9; i++)
        {
            nums.push_back(i);
        }
       
        backtrack({}, nums, k, n, 0);
         
        return {res.begin(), res.end()};
    }
};