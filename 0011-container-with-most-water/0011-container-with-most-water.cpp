class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0, r = height.size()-1;
        
        int curArea, maxArea = 0;
        
        while(l < r)
        {
           curArea = min(height[l], height[r]) * (r-l);
            
            if(curArea > maxArea)
            {
                 maxArea = curArea;
            }
            
            if(height[l]> height[r])
                r--;
            
            else l++;
        }
        
        return maxArea;
    }
};