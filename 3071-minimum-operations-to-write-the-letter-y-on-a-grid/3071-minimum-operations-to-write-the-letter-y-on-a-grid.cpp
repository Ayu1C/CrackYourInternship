class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> v(n, vector<int>(n, -1));
        int i = 0;
        int cnt = 0, cnt1 = 0, cnt2 = 0;

        while (i < n / 2) {
            if (grid[i][i] == 1) cnt1++;
            if (grid[i][i] == 2) cnt2++;
            if (grid[i][i] == 0) cnt++;
            if (grid[i][n - i - 1] == 1) cnt1++;
            if (grid[i][n - i - 1] == 2) cnt2++;
            if (grid[i][n - i - 1] == 0) cnt++;
            v[i][i] = 1;
            v[i][n - i - 1] = 1;
            i++;
        }
        if (grid[n / 2][n / 2] == 1) cnt1++;
        if (grid[n / 2][n / 2] == 2) cnt2++;
        if (grid[n / 2][n / 2] == 0) cnt++;
        v[n / 2][n / 2] = 1;

        i = n / 2 + 1;
        while (i < n) {
            if (grid[i][n / 2] == 1) cnt1++;
            if (grid[i][n / 2] == 2) cnt2++;
            if (grid[i][n / 2] == 0) cnt++;
            v[i][n / 2] = 1;
            i++;
        }
        int rcnt = 0, rcnt1 = 0, rcnt2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == -1) {
                    if (grid[i][j] == 1) rcnt1++;
                    if (grid[i][j] == 2) rcnt2++;
                    if (grid[i][j] == 0) rcnt++;
                }
            }
        }
        unordered_map<int,int>mp,mp1;
        mp[0]=cnt,mp[1]=cnt1,mp[2]=cnt2;
        mp1[0]=rcnt,mp1[1]=rcnt1,mp1[2]=rcnt2;
        int sum=cnt+cnt1+cnt2;
        int minia=1e9;
        for(auto it :mp){
            int temp= sum-it.second;
            int minii= 1e9;
            for(auto kt : mp1){
                if(kt.first==it.first){
                    temp+=kt.second;
                }
                else{
                    minii=min(kt.second,minii);
                }
            }
            minia=min(temp+minii,minia);
        }

        return minia;
    }
}; 