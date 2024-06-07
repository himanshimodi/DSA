class Solution {
public:
    
unordered_map <int, bool> rowCheck;
unordered_map <int, bool> upperLeftDiagonalCheck;
unordered_map <int, bool> bottomLeftDiagonalCheck;

void storeSolution( vector<vector<char>> & board, int n, vector<vector<string>> &ans){
	vector<string> temp;
	for(int i=0; i<n; i++){
		string output="";
		for(int j=0; j<n; j++){
			output.push_back(board[i][j]);
                }
	        temp.push_back(output);
	}
	ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n){
	
	//check left row
	if(rowCheck[row] == true)
	   return false;
	
	//check upper Left Diagonal
	if(upperLeftDiagonalCheck[n-1+col-row] == true)
	   return false;

	//check bottom left Diagonal 
	if(bottomLeftDiagonalCheck[row+col] == true)
	   return false;
	
	//else
	return true;
}

void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans){

	//base case
	if(col >= n){
	  storeSolution(board, n, ans);
	  return;
	}

	//ek case solve krdo baki recursion sambhal lega
	for(int row=0; row<n; row++){
	   if(isSafe(row, col, board, n)){
	     //place the Queen
	     board[row][col] = 'Q';
	     rowCheck[row] = true;
	     upperLeftDiagonalCheck[n-1+col-row] = true;
	     bottomLeftDiagonalCheck[row+col] = true;
		
	     //recursion
	     solve(board, col+1, n, ans);

	     //backtracking
	     board[row][col] = '.';
	     rowCheck[row] = false;
	     upperLeftDiagonalCheck[n-1+col-row] = false;
	     bottomLeftDiagonalCheck[row+col] = false;
	   }
	}
}

vector<vector<string>> solveNQueens(int n){
	vector<vector<char>> board (n, vector<char>(n,'.'));
	vector<vector<string>> ans;
	int col=0;
	solve(board, col, n, ans);

	return ans;
}
	
};

