class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> count;
        
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto it : count)
        {
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<int> ans;
        
        while(k--)
        {
            pair<int, int> ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        
        return ans;
    }
};