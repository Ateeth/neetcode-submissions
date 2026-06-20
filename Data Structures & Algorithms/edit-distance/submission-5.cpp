class Solution {
public:
    int f(int i, int j, string word1, string word2, vector<vector<int>>& dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        // int match = INT_MAX, notMatch = INT_MAX;
        if(word1[i] == word2[j]){
            return dp[i][j] =  f(i-1,j-1,word1, word2, dp);
        } else {
            int insert = f(i, j-1, word1, word2, dp);
            int del = f(i-1, j, word1, word2, dp);
            int rep = f(i-1, j-1, word1, word2, dp);
            
            return dp[i][j] =  1 + min(insert, min(del, rep));
        }

        // return min(match, notMatch);
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        // vector<vector<int>> dp(m, vector<int>(n , -1));
        // return f(m-1, n-1, word1, word2, dp);

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // for(int j = 0 ; j <= n ; ++j){
        //     dp[0][j] = j;
        // }

        // for(int i = 1 ; i <= m ; ++i){
        //     dp[i][0] = i;
        // }

        // for(int i = 1 ; i <= m ; ++i){
        //     for(int j = 1 ; j <= n ; ++j){
        //         if(word1[i-1] == word2[j-1]){
        //             dp[i][j] = dp[i-1][j-1];
        //         } else {
        //             int insert = dp[i][j-1];
        //             int del = dp[i-1][j];
        //             int rep = dp[i-1][j-1];
                    
        //             dp[i][j] =  1 + min(insert, min(del, rep));
        //         }
        //     }
        // }
        // return dp[m][n];

        vector<int> prev(n + 1, 0);
        for(int j = 0 ; j <= n ; ++j){
            prev[j] = j;
        }

        for(int i = 1 ; i <= m ; ++i){
            vector<int> curr(n + 1 , 0);
            curr[0] = i;
            for(int j = 1 ; j <= n ; ++j){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                } else {
                    int insert = curr[j-1];
                    int del = prev[j];
                    int rep = prev[j-1];
                    
                    curr[j] =  1 + min(insert, min(del, rep));
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
