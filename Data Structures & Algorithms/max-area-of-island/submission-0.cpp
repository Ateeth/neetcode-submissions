class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[i][j] = true;
        queue<pair<int, int>> q;
        int size = 0;
        q.push({i, j});

        int delRow[] = {1,-1,0,0};
        int delCol[] = {0,0,-1,1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int k = 0 ; k < 4 ; ++k){
                int nr = r + delRow[k];
                int nc = c + delCol[k];

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc] == 1){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            ++size;
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i = 0 ; i < rows; ++i){
            for(int j = 0 ; j < cols ; ++j){
                if(!visited[i][j] && grid[i][j] == 1){
                    ans = max(ans, bfs(i, j, grid, visited));
                }
            }
        }

        return ans;
    }
};
