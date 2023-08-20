class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        vector<vector<int>> ans;
        int temp, i;
        
        for(i=0; i<intervals.size(); i++)
        {
            if(intervals[i][0] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] >= newInterval[0])
            {
                if(!ans.empty() && ans.back()[1]>=newInterval[0])
                {
                   ans.back()[1] = max(newInterval[1], ans.back()[1]); 
                }
                else
                    ans.push_back(newInterval);
                temp = i;
                break;
            }
        }
        
        if(i==intervals.size())
        {
            if(!ans.empty() && ans.back()[1]>=newInterval[0])
            {
               ans.back()[1] = max(newInterval[1], ans.back()[1]); 
            }
            else ans.push_back(newInterval);
            return ans;
        }
        
        for(int j=temp; j<intervals.size(); j++)
        {
            if(!ans.empty() && ans.back()[1]>=intervals[j][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[j][1]);
            }
            else
                ans.push_back(intervals[j]);
        }
        
        return ans;
    }
};