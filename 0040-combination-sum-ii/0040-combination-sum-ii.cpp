class Solution {
public:
    
    //basic concept - at every index we are checking, if on taking this ele in our curr combination, we are getting result or not, if got, add to combinations, else backtrack and remove this element, and move to next index..
    
    void backtrack(vector<int> cur_comb, int index, vector<int>& candidates, int target, vector<vector<int>>& res)
    {
        if(target==0)
        {
           res.push_back(cur_comb);
            return;
        }
        
        if(index >= candidates.size() || target < 0) return;
        
        for(int i=index; i<candidates.size(); i++)
        {
             if(i>index && candidates[i]==candidates[i-1]) continue;
            cur_comb.push_back(candidates[i]);
            backtrack(cur_comb, i+1, candidates, target-candidates[i], res);
            cur_comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        
        backtrack({}, 0, candidates, target, res);
        
        return res;
    }
};

