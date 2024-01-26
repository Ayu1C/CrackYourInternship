class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int l = n, r = 0;
        
        if(right.size() != 0) l = *min_element(right.begin(), right.end());
        if(left.size() != 0) r = *max_element(left.begin(), left.end());
        
        int ans = max(abs(n-l), abs(r-0));
        
        return ans;
    }
};