class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r=matrix.size();
        int c = matrix[0].size();
        int i=0,j=0;
        int s=r,t=c;
      
        bool found = 0,present=1;
        while(i<r && j<c)
        {
            if(target < matrix[i][j] || target > matrix[s-1][t-1])
            {
                present = 0;
                break;
            }
            else if(target >= matrix[i][j] && target <= matrix[i][t-1])
            {
                for(int a=j; a<t; a++)
                {
                    if(matrix[i][a]==target)
                    {
                        found = 1;
                        break;
                    }
                    
                }
                if(found!=1)
                {
                        present = 0;
                        break;
                }
            }
            else if(target > matrix[i][t-1])
            {
                i++;
            }
            if(found==1 || present==0)
            {
                break;
            }

        }
        if(found==1)
        {
            return true;
        }
        else
           return false;
    }
};