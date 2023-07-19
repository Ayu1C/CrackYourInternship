class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size()==1) return 0;
        
        int ans=0;
        
        sort(intervals.begin(), intervals.end());
        
        int prev = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(prev > intervals[i][0])
            {
                ans++;
                prev = min(prev, intervals[i][1]);
            }
            else
            {
                prev = intervals[i][1];
            }
        }
        
        return ans;
    }
};