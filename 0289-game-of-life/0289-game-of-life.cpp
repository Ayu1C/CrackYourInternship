class Solution {
public:

    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
	int liveNeighbours = 0;
	if(i>0) {
		//check the upper neighbour
		if(curr[i-1][j] == 1) liveNeighbours++;
	}
	if(i<m-1) {
		//check the lower neighbour
		if(curr[i+1][j] == 1) liveNeighbours++;
	}
	if(j>0) {
		//check the left neighbour
		if(curr[i][j-1] == 1) liveNeighbours++;
	}
	if(j<n-1) {
		//check the right neighbour
		if(curr[i][j+1] == 1) liveNeighbours++;
	}

    //check the diagonally left cell upwards
	if(i>0 && j>0) {
		if(curr[i-1][j-1] == 1) liveNeighbours++;
	}
        
     //check the diagonally right cell upwards   
	if(i>0 && j<n-1) {
		if(curr[i-1][j+1] == 1) liveNeighbours++;
	}
        
    //check the diagonally left cell downwards    
	if(i<m-1 && j>0) {
		if(curr[i+1][j-1] == 1) liveNeighbours++;
	}
        
    //check the diagonally right cell downwards    
	if(i<m-1 && j<n-1) {
		if(curr[i+1][j+1] == 1) liveNeighbours++;
	}
	return liveNeighbours;
}
    
    
void gameOfLife(vector<vector<int>>& board) {
    
    // we are using new matrix to remember our actual board, and making the changes in original board, bcz it is given that the states changed dont affect next cells.
    
	vector<vector<int>> curr = board;
	int m = board.size();
	int n = board[0].size();
	for(int i = 0; i<m; i++) {
		for(int j = 0; j<n; j++) {
			int ln = getLiveNeighbours(curr, i, j, m, n);
			if(board[i][j] == 0) {
				//currently dead
				//can become alive if has exactly three live neighbours
				if(ln == 3) {
					board[i][j] = 1;
				}
			}
			else if(board[i][j] == 1) {
				// ln<2 -> die
				// ln==2 || ln==3 live
				// ln>3 ->die
				if(ln < 2 || ln > 3) {
					board[i][j] = 0;
				}
			}
		}
	}
}
        
};