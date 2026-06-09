class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }

    bool solve(vector<vector<char>>& board){

        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                // sudoku solver
                // // empty cell try filling from 1 to 9
                // if(board[i][j] == '.'){
                //     for(char ch = '1' ; ch < '10' ; ++ch){
                //         if(isValid(board, i, j, ch)){
                //             board[i][j] = ch;
                //             // try to solve the rest of sudoku
                //             if(solve(board)){
                //                 return true;
                //             } else {
                //                 // board was not solvable
                //                 board[i][j] = '.';
                //             }
                //         }
                //     }

                //     // none from 1 to 9 resulted in valid sudoku
                //     return false;
                // }

                // if number see if it valid
                if(board[i][j] != '.'){
                    if(!isValid(board, i , j, board[i][j])) return false;
                }
            }
        }

        return true;
    }

    bool isValidSolver(vector<vector<char>>& board, int row, int col, char ch){
        // check col
        for(int i = 0 ; i < 9 ; ++i){
            if(board[row][i] == ch) return false;
        }

        // check row
        for(int i = 0 ; i < 9 ; ++i){
            if(board[i][col] == ch) return false;
        }

        // check box
        for(int i = 0 ; i < 9 ; ++i){
            int rc = 3 * (row / 3) + (i / 3);
            int cc = 3 * (col / 3) + (i % 3);
            if(board[rc][cc] == ch) return false;
        }

        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        // check col
        for(int i = 0 ; i < 9 ; ++i){
            if(i != col && board[row][i] == ch) return false;
        }

        // check row
        for(int i = 0 ; i < 9 ; ++i){
            if(i != row && board[i][col] == ch) return false;
        }

        // check box
        for(int i = 0 ; i < 9 ; ++i){
            int rc = 3 * (row / 3) + (i / 3);
            int cc = 3 * (col / 3) + (i % 3);
            if(rc == row && cc == col) continue;
            if(board[rc][cc] == ch) return false;
        }

        return true;
    }
};
