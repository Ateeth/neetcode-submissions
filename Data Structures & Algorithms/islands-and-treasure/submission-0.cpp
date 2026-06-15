class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = pow(2,31) - 1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int delRow[] = {0,0,1,-1};
        int delCol[] = {1,-1,0,0};

        queue<pair<int, int>> q;

        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0; j < grid[0].size() ; ++j){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dis = 1;
        while(!q.empty()){
            int size = q.size();
            for(int s = 0 ; s < size; ++s){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0 ; i < 4 ; ++i){
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];

                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == INF){
                        grid[nr][nc] = dis;
                        q.push({nr, nc});
                    }
                }
            }
            ++dis;
        }
    }
};
