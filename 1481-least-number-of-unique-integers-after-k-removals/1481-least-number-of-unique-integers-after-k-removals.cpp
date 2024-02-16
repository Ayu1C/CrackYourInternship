class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        map<int, int> mp;
        
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> v;
        for (auto& it : mp) { 
          v.push_back(it.second); 
        } 
        
        sort(v.begin(), v.end());
        
        // Tracking the number of elements removed
        int elementsRemoved = 0;

        for (int i = 0; i < v.size(); i++) {
            // Removing frequencies[i] elements which equates to
            // removing one unique element
            elementsRemoved += v[i];

            // If the number of elements removed exceeds k, we'll return
            // the remaining number of unique elements.
            if (elementsRemoved > k) {
                return v.size() - i;
            }
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};