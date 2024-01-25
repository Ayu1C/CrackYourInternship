class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(begin(arr2), end(arr2));
        int ans = 0;
        for (int i : arr1) {
            if (upper_bound(begin(arr2), end(arr2), i + d) == lower_bound(begin(arr2), end(arr2), i - d)) ++ans;
        }
        return ans;
    }
};