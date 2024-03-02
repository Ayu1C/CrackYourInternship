class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int op = 0;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        
        while(!pq.empty())
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            if(a >= k && b >= k) break;
            
            pq.push(min(a,b)*2 + max(a,b));
            
            op++;
        }
        
        return op;
    }
};