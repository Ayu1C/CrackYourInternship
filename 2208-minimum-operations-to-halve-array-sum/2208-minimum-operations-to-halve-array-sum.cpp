class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        double sum = 0;
        int oper = 0;
        priority_queue<double> pq;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        
        double half_sum = sum/(double)2;
        
        while(!pq.empty())
        {
            double maxe = pq.top();
            pq.pop();
            
            pq.push(maxe/(double)2);
            
            sum -= maxe/(double)2;
            
            oper++;
            
            if(sum <= half_sum) break;
        }
        
        return oper;
    }
};