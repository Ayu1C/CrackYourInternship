class Solution {
public:
    
    // sorting by minimum end
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        
        int c=1;
        int e=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            int si=pairs[i][0], ei=pairs[i][1];
            
			// including current pair as part of chain
            if(si>e){
                c++;
                e=max(e,ei);
            }
        }
        return c;
    }
    
};