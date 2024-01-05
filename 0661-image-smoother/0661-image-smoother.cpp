class Solution {
public:
    int row, col;
    
    bool isValid(int r, int c)
    {
        if(r>=0 && r<row && c>=0 && c<col) return 1;
        return 0;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(), n = img[0].size();
        row = m, col = n;
        
        vector<vector<int>> filtered(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int cellr = i, cellc = j;
                double sum = 0, totaln = 0;
                
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(isValid(cellr+dr, cellc+dc))
                        {
                            sum += img[cellr+dr][cellc+dc];
                            totaln += 1;
                        }
                    }
                }
                
                // cout << sum << endl; 
                // cout << totaln << endl;
                double smoother = floor(sum/totaln);
                
                filtered[cellr][cellc] = (int)smoother;
            }
        }
        
        return filtered;
    }
};