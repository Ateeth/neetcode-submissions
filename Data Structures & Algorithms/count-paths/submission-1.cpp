class Solution {
public:
    int f(int r, int c, vector<vector<int>>& dp){
        if(r == 0 || c == 0) return 1;

        if(dp[r][c] != -1) return dp[r][c];
        int left = f(r, c - 1, dp);
        int up = f(r - 1, c, dp);

        return dp[r][c] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n , -1));
        return f(m-1, n-1, dp);
    }
};
