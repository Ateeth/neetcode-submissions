class Solution {
public:
    bool isValid(char ch, int r, int c, vector<vector<char>>& board){
        // check row 
        for(int i = 0 ; i < 9; ++i){
            if(i == c) continue;
            if(board[r][i] == ch) return false;
        }

        // check column
        for(int i = 0 ; i < 9 ; ++i){
            if(i == r) continue;
            if(board[i][c] == ch) return false;
        }

        for(int i = 0 ; i < 9 ; ++i){
            int rc = 3 * (r / 3) + i/3;
            int cc = 3 * (c/3) + i % 3;
            if(rc == r && cc == c) continue;
            if(board[rc][cc] == ch) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j] != '.'){
                    if(!isValid(board[i][j], i, j , board)) return false;
                }
            }
        }

        return true;
    }
};
