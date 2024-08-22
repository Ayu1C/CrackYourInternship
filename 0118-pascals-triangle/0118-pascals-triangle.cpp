class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> pascal;
        
        pascal.push_back({1});
        
        for(int r = 1; r < numRows; r++) {
            vector<int> temp;
            for(int c = 0; c <= r; c++) {
                if(c == 0 || c == r) temp.push_back(1);
                else temp.push_back(pascal[r-1][c-1] + pascal[r-1][c]);
            } 
            pascal.push_back(temp);
        }
        
        return pascal;
    }
};