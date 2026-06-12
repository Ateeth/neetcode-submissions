class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n ,'.');

        for(int i = 0 ; i < n ; ++i){
            board[i] = s;
        }

        solve(0, n, ans, board);
        return ans;
    }

    void solve(int col, int n, vector<vector<string>>& ans, vector<string>& board){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < n ; ++i){
            if(canPlace(board, i, col)){
                board[i][col] = 'Q';
                solve(col+1, n, ans, board);
                board[i][col] = '.';
            } 
        }
    }

    bool canPlace(vector<string>& board, int row, int col){
        // upper left check
        int r = row - 1, c = col - 1;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            --r;
            --c;
        }

        c = col - 1, r = row;
        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            --c;
        }

        r = row + 1, c = col - 1;
        while(r < board.size() && c >= 0){
            if(board[r][c] == 'Q') return false;
            ++r;
            --c;
        }

        return true;
    }
};
