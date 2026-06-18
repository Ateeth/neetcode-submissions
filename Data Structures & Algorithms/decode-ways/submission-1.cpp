class Solution {
public:
    int f(int idx, string s, vector<int>& dp){
        if(idx < 0) return 1;
        if(dp[idx] != -1) return dp[idx];
        int ways = 0;
        if(s[idx] != '0') ways += f(idx-1, s, dp);

        if(idx > 0){
            int num = (s[idx - 1] - '0') * 10 + (s[idx]  - '0');
            if(num >= 10 && num <= 26) ways += f(idx - 2 , s, dp);
        }

        return dp[idx] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n , -1);
        return f(n-1, s, dp);
    }
};
