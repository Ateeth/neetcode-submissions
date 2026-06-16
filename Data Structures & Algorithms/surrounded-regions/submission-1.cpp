class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<int>> visited(r, vector<int>(c, 0));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < r ; ++i){
            for(int j = 0 ; j < c ; ++j){
                if(i == 0 || i == r-1 || j == 0 || j == c-1){
                    if(board[i][j] == 'O'){
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int delRow[] = {0,0,1,-1};
        int delCol[] = {1,-1,0,0};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0 ; k < 4 ; ++k){
                int ni = i + delRow[k];
                int nj = j + delCol[k];

                if(ni >= 0 && ni < r && nj >=0 && nj < c && !visited[ni][nj] && board[ni][nj] == 'O'){
                    visited[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }

        for(int i = 0 ; i < r ; ++i){
            for(int j = 0 ; j < c ; ++j){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
