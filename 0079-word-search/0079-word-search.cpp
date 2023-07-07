class Solution {
public:
    bool search(int i, int j, int r, int c, vector<vector<char>>& board, string word, int k )
    {
        if(k == word.size()) return true;
        
        if(i<0 || j<0 || i==r || j==c || board[i][j] != word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool b1 = search(i+1, j, r, c, board, word, k+1);
        bool b2 = search(i, j+1, r, c, board, word, k+1);
        bool b3 = search(i-1, j, r, c, board, word, k+1);
        bool b4 = search(i, j-1, r, c, board, word, k+1);
        
        board[i][j] = temp;
        
        
        return (b1 || b2 || b3 || b4);
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
    
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(board[i][j]==word[0])
                {
                    if(search(i, j, r, c, board, word, 0)) return true;
                }
            }
        }
        
        return false;
        
    }
};