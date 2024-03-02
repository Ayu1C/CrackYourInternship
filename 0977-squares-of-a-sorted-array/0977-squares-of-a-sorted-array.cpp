class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> temp, ans;
        
        int pt = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                temp.push_back(nums[i]);
                pt++;
            } 
            else 
                break;
        }
        
        int neg = 0;
        reverse(temp.begin(), temp.end());
        
        while(neg < temp.size() && pt < nums.size())
        {
            if(pow(temp[neg], 2) <= pow(nums[pt], 2))
            {
                ans.push_back(pow(temp[neg], 2));
                neg++;
            }
            else {  
                ans.push_back(pow(nums[pt], 2));
                pt++;
            }
        }
        
        while(neg < temp.size())
        {
             ans.push_back(pow(temp[neg], 2));
             neg++; 
        }
        
        while(pt < nums.size())
        {
            ans.push_back(pow(nums[pt], 2));
             pt++;
        }
        
        return ans;
    }
};