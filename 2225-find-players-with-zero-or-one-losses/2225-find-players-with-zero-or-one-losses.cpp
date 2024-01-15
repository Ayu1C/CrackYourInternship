class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, int> lost, all;
        
        for(int i=0; i<matches.size(); i++)
        {
            lost[matches[i][1]]++;
            all[matches[i][0]]++;
        }
        
        vector<vector<int>> ans;
        vector<int> notLost, lost1;
        
        for(auto it : all)
        {
            if(lost.find(it.first) == lost.end())
                notLost.push_back(it.first);
        }
        
        for(auto it : lost)
        {
            if(it.second == 1) lost1.push_back(it.first);
        }
        
        ans.push_back(notLost);
        ans.push_back(lost1);
        
        return ans;
    }
};