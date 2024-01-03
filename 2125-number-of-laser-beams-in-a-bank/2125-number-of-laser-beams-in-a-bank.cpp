class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int m = bank.size(), n = bank[0].size(), ans = 0, prevRowSD = 0;
        
        for(int r=0; r<m; r++)
        {
             int nOfSD = 0;
            for(int c=0; c<n; c++)
            {
                if(bank[r][c] == '1') nOfSD++;
            }
            ans += prevRowSD * nOfSD;
            if(nOfSD != 0) prevRowSD = nOfSD;
        }
        
        return ans;
    }
};