class Solution {
public:
    
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
    return maxi;
   }
    
    long long calculateTotalHours(vector<int> &v, int hourly) {
          double totalH = 0;
          int n = v.size();
          //find total hours:
          for (int i = 0; i < n; i++) {
              totalH += ceil((double)(v[i]) / (double)(hourly));
          }
          return trunc(totalH);
   }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = findMax(piles);

        //apply binary search:
       while (low <= high) {
        int mid = (low + high) / 2;
        long long totalH = calculateTotalHours(piles, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
        return low;
    }
};