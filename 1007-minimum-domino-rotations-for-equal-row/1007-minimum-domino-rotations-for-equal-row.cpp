class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n = tops.size();
        map<int, int> mp1, mp2;
        
        for(int i=0; i<n; i++)
        {
           if(mp1.find(tops[i]) != mp1.end()) mp1[tops[i]]++;
           else mp1[tops[i]] = 1;
            
           if(mp2.find(bottoms[i]) != mp2.end()) mp2[bottoms[i]]++;
           else mp2[bottoms[i]] = 1;    
        }
        
        // for(auto &i : mp1) cout << i.first << "-" << i.second << " ";
        // cout << endl;
        // for(auto i : mp2) cout << i.first << "-" << i.second << " ";
        // cout << endl;
        
        
        int maxV1 = INT_MIN, maxV2 = INT_MIN;
        int maxK1 = INT_MIN, maxK2 = INT_MIN;
        
        for(const auto &it : mp1)
        {
             if(it.second > maxV1)
             {
                maxK1 = it.first;
                maxV1 = it.second;
             }
        }
        
        for(const auto &itr : mp2)
        {
             if(itr.second > maxV2)
             {
                maxK2 = itr.first;
                maxV2 = itr.second;
             }
        }
        
        //cout << max1 << " " << max2 << endl;
        
        int count1 = 0, count2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(tops[i] != maxK1)
            {
                if(bottoms[i]==maxK1) count1++;
                else{
                    count1 = n+1;
                    break;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(bottoms[i] != maxK2)
            {
                if(tops[i]==maxK2) count2++;
                else{
                    count2 = n+1;
                    break;
                }
            }
        }
    
        //cout << count1 << " " << count2 << endl;
        
        if(count1 == n+1 && count2 == n+1) return -1;
        
        return min(count1, count2);
    }
};