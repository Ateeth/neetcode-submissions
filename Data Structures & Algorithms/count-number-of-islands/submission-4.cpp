class Solution {
public:
    void bfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        visited[r][c] = true;
        queue<pair<int, int>> q;
        q.push({r, c});

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0 ; k < 4 ; ++k){
                int ni = i + delRow[k];
                int nj = j + delCol[k];

                if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !visited[ni][nj] && grid[ni][nj] == '1'){
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ctr = 0 ;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0 ; j < grid[0].size(); ++j){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    bfs(i, j, visited, grid);
                    ++ctr;
                }
            }
        }
        return ctr;
    }
};
