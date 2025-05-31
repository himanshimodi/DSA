class Solution {
public:
    //NOT SOLVING SUDOKU, SIRF VALIDATE KRNA HAI 
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        int rows = board.size();
        int cols = board[0].size();

        for(int i =0;i<rows;i++){
            for(int j=0;j<cols; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                char curr = board[i][j];
                string newrow = "row"+to_string(i)+"-"+curr;
                string newcol = "col"+to_string(j)+"-"+curr;
                string boxidx = "box"+to_string(i/3)+to_string(j/3)+"-"+curr;

                if(seen.count(newrow)|| seen.count(newcol)||seen.count(boxidx)){
                    return false;//matlab duplicate milgya
                }

                //matlab element nhi hai toh seen krdo
                seen.insert(newrow);
                seen.insert(newcol);
                seen.insert(boxidx);

            }
        }
        return true;
    }
};