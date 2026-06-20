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
        vector<vector<int>> dp(m, vector<int>(n , -1));
        return f(m-1, n-1, word1, word2, dp);
    }
};
