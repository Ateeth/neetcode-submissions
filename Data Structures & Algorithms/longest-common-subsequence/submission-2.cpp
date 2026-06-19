class Solution {
public:
    int f(int i, int j, string text1, string text2, vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int take = 0;
        if(text1[i - 1] == text2[j - 1]){
            take = 1 + f(i - 1, j - 1, text1, text2, dp);
        }
        int notTake = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));

        return dp[i][j] = max(take, notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size(), s2 = text2.size();
        // vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));
        // return f(s1, s2, text1, text2, dp);

        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        for(int i = 1 ; i <= s1 ; ++i){
            for(int j = 1 ; j <= s2 ; ++j){
                int take = 0;
                if(text1[i-1] == text2[j-1]){
                    take = 1 + dp[i-1][j-1];
                }

                int notTake = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(take, notTake);
            }
        }

        return dp[s1][s2];
    }
};
