class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& nums) {
        
        int r = nums.size(), c = nums[0].size();

       //left_Prod[i] stores product of all elements to the left of nums[i], and right_Prod[i] stores
       // product of all elements to the right of nums[i];

       vector<vector<unsigned long long>> left_Prod(r, vector<unsigned long long>(c, 1)), right_Prod(r, vector<unsigned long long>(c, 1));
        
       vector<vector<int>> ans(r, vector<int>(c, 1));
        
       left_Prod[0][0] = 1;

       for(int i=0; i<r; i++)
       {
           for(int j=0; j<c; j++)
           {
               if(i==0 && j==0) continue;
               
               if(j==0)
               {
                   left_Prod[i][j] = (left_Prod[i-1][c-1] * nums[i-1][c-1]) % 12345;
               }
               else 
                  left_Prod[i][j] = (left_Prod[i][j-1] * nums[i][j-1]) % 12345;
           }
       }
        
       right_Prod[r-1][c-1] = 1;

       for(int i=r-1; i>=0; i--)
       {
           for(int j=c-1; j>=0; j--)
           {
               if(i==r-1 && j==c-1) continue;
               
               if(j==c-1)
               {
                   right_Prod[i][j] = (right_Prod[i+1][0] * nums[i+1][0]) % 12345;
               }
               else
                  right_Prod[i][j] = (right_Prod[i][j+1] * nums[i][j+1]) % 12345;
           }
       }

       for(int i=0; i<r; i++)
       {
           for(int j=0; j<c; j++)
           {
              ans[i][j] = (int)((left_Prod[i][j] * right_Prod[i][j]) % 12345);
           }
       }

       return ans;
    }
};