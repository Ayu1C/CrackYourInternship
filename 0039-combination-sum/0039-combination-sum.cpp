class Solution {
public:
    void backtrack(vector<int> cur_comb, int index, vector<int>& candidates, int target, vector<vector<int>>& res)
    {
        if(index >= candidates.size() || target < 0) return;
        
        if(target==0)
        {
           res.push_back(cur_comb);
            return;
        }
        
        for(int i=index; i<candidates.size(); i++)
        {
            if(i!=0 && candidates[i]==candidates[i-1]) continue;
            cur_comb.push_back(candidates[i]);
            backtrack(cur_comb, i, candidates, target-candidates[i], res);
            cur_comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        
        backtrack({}, 0, candidates, target, res);
        
        return res;
    }
};