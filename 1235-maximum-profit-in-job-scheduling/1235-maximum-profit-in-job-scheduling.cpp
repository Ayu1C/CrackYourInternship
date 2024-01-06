// If we sort jobs by start time, starting from job index cur = 0, we might either schedule the jobs[cur] or not.

// If we schedule jobs[cur], the problem becomes profit of jobs[cur] + max profit of scheduling jobs starting from next available job index.
// If we don't schedule jobs[cur], the problem becomes max profit of scheduling jobs starting from cur + 1.
// We choose the one giving more profits

class Solution {
public:
   
    int jobScheduling( vector<int> startTime, vector<int> endTime, vector<int> profit) {
        
        map<int, int> dp;
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        int maxT = 0;
        for (auto job : jobs) {
            auto it = dp.lower_bound(job[1]);
            int pre = (it == dp.end()) ? 0 : it->second;
            maxT = max(maxT, job[2] + pre);
            dp[job[0]] = maxT;
        }
        
        return maxT;
        
    }
};