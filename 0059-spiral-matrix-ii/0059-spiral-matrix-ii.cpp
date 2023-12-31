class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> spiral(n, vector<int>(n, 0));
        
        int startr = 0, startc = 0, endr = n-1, endc = n-1;
        
        int num = 1;
        
        while(startr <= endr && startc <= endc)
        {
            for(int i=startc; i<=endc; i++)
            {
               spiral[startr][i] =  num++;
            }
            startr++;
            
            for(int i=startr; i<=endr; i++)
            {
               spiral[i][endc] =  num++;
            }
            endc--;
            
            for(int i=endc; i>=startc; i--)
            {
               spiral[endr][i] =  num++;
            }
            endr--;
            
            for(int i=endr; i>=startr; i--)
            {
               spiral[i][startc] =  num++;
            }
            startc++;
            
        }
        
        return spiral;
    }
};