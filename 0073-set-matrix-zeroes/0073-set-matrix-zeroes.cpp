class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
       set<int> row, col;
        
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[0].size(); c++) {
                if(matrix[r][c] == 0) {
                    row.insert(r);
                    col.insert(c);
                }
            }
        }
        
        for(int r = 0; r < matrix.size(); r++) {
            if(row.find(r) != row.end()) {
                for(int c = 0; c < matrix[0].size(); c++) {
                    matrix[r][c] = 0;
                }
            }
        }
        
        for(int c = 0; c < matrix[0].size(); c++) {
            if(col.find(c) != col.end()) {
                for(int r = 0; r < matrix.size(); r++) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};