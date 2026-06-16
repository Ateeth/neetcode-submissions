class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        visited[r][c] = true;
        int delRow[] = {0,0,-1,1};
        int delCol[] = {1,-1,0,0};
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0 ; k < 4 ; ++k){
                int nr = i + delRow[k];
                int nc = j + delCol[k];

                if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && heights[i][j] <= heights[nr][nc] && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        
        // pacific first row first column
        for(int i = 0 ; i < heights[0].size() ; ++i){
            bfs(0,i,heights, pacific);
        }
        for(int i = 0 ; i < heights.size(); ++i){
            bfs(i, 0, heights, pacific);
        }

        // atlantic last row last column
        for(int i = 0; i < heights[0].size(); ++i){
            bfs(heights.size() - 1, i , heights, atlantic);
        }
        for(int i = 0 ; i < heights.size() ; ++i){
            bfs(i, heights[0].size()-1, heights, atlantic);
        }

        vector<vector<int>> ans;
        for(int i = 0 ; i < heights.size(); ++i){
            for(int j = 0 ; j < heights[0].size(); ++j){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
