class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];
        
        priority_queue<int> pq; //max heap
        
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        
        k -= 1;
        while(k--)
        {
            pq.pop();
        }
        
        return pq.top();
        
    }
};