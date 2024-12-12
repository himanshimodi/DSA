class Solution {
public:
    bool solve(vector<vector<char>>& B, string& word, int row, int col,
               int index) {
        // BC
        // all chars matched
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || row >= B.size() || col < 0 || col >= B[0].size() ||
            B[row][col] != word[index]) {
            return false;
        }

        // ek case
        // marking this cell visited
        char temp = B[row][col];
        B[row][col] = '.';
        bool found = solve(B, word, row + 1, col, index + 1) ||
                     solve(B, word, row - 1, col, index + 1) ||
                     solve(B, word, row, col + 1, index + 1) ||
                     solve(B, word, row, col - 1, index + 1);
        // unvisited
        B[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int index = 0; // this is index of word
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(board, word, i, j, index)) {
                    return true;
                }
            }
        }
        return false;
    }
};