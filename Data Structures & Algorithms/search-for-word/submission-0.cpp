class Solution {
public:

    bool f(int idx, int r, int c,
       string& word,
       vector<vector<char>>& board,
       vector<vector<bool>>& vis){

        if(r < 0 || r >= board.size() ||
        c < 0 || c >= board[0].size())
            return false;

        if(vis[r][c] || board[r][c] != word[idx])
            return false;

        if(idx == word.size() - 1)
            return true;

        vis[r][c] = true;

        bool found =
            f(idx + 1, r - 1, c, word, board, vis) ||
            f(idx + 1, r + 1, c, word, board, vis) ||
            f(idx + 1, r, c - 1, word, board, vis) ||
            f(idx + 1, r, c + 1, word, board, vis);

        vis[r][c] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for(int i = 0 ; i < r; ++i){
            for(int j = 0 ; j < c; ++j){
                if(f(0,i,j,word,board,vis)) return true;
            }
        }
        return false;
    }
};
