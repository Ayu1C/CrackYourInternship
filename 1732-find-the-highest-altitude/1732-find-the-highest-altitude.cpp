class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int cur = 0, highest = 0;
        
        for(int i=0; i<gain.size(); i++)
        {
            cur += gain[i];
            highest = max(highest, cur);
        }
        
        return highest;  
    }
};