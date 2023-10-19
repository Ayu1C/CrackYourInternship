class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        int n = row.size();
        
        map<int, int> mp;
        
        for(int i=0; i<n; i+=2)
        {
            mp[i] = i+1;
            mp[i+1] = i;
        }
        
        int swaps=0;
        
        for(int i=0; i<n; i+=2)
        {
           int j = i+1;
           if(mp[row[i]]==row[j] || mp[row[j]]==row[i])
           {
               continue;
           }
            else
            {
                for(int k=j+1; k<n; k++)
                {
                    if(mp[row[i]]==row[k] || mp[row[k]]==row[i])
                    {
                        swap(row[j], row[k]);
                        swaps++;
                        break;
                    }
                }
            }
        }
        
        return swaps;
    }
};