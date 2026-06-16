class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nFresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0 ; i < grid.size(); ++i){
            for(int j = 0 ; j < grid[0].size() ; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }

                if(grid[i][j] == 1) ++nFresh;
            }
        }

        int time = 0;
        int delRow[] = {1,-1,0,0};
        int delCol[] = {0,0,1,-1};

        while(!q.empty()  && nFresh > 0){
            int size = q.size();
            for(int i = 0 ; i < size; ++i){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int k = 0 ; k < 4 ; ++k){
                    int nr = r + delRow[k];
                    int nc = c + delCol[k];

                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        --nFresh;
                        q.push({nr, nc});
                    }
                }
            }
            ++time;
        }
        if(nFresh != 0) return -1;
        return time;
    }
};
