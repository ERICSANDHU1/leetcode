class Solution {
public:

    bool check(int row, int col, char c, vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            if(board[row][i] == c) return false; // row
            if(board[i][col] == c) return false; // col
        }

        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[sr + i][sc + j] == c) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    for(char c = '1'; c <= '9'; c++) {

                        if(check(i, j, c, board)) {

                            board[i][j] = c;

                            if(solve(board))
                                return true;

                            // backtrack
                            board[i][j] = '.';
                        }
                    }

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