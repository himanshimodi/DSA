class Solution {
public:

    bool isSafe(char digit, int row, int col,vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            //row check
            if(board[row][i]==digit){
                return false;
            }
            //col check
            if(board[i][col]==digit){
                return false;
            }
            //3x3 box check
             if(board[3*(row/3)+i/3][3*(col/3)+i%3] == digit){
                return false;
            }
        }
        return true;
    }


    bool solve(vector<vector<char>>&board){
        //BC->this question does not need one

        //traversing the board
        for(int i=0; i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    for(char digit='1';digit<='9';digit++){
                        if(isSafe(digit,i,j,board)==true){
                            board[i][j] = digit;
                            //RE
                            bool aageSolveHogya = solve(board);
                            if(aageSolveHogya==true){
                                return true;
                            }else{
                                //Backtrack
                                board[i][j]='.';
                            }                            
                        }
                    }
                    //digit is not fitting
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};