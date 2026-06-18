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
        // vector<int> dp(n , -1);
        // return f(n-1, s, dp);

        vector<int> dp(n + 1 , 0);
        dp[0] =1;

        for(int i = 1 ; i <= n ; ++i){
            int ways= 0;
            if(s[i-1] != '0') ways += dp[i-1];
            
            if(i > 1){
                int nums = 10 * (s[i-2] - '0') + (s[i-1] - '0');
                if(nums >= 10 && nums <= 26) ways += dp[i - 2];
            }

            dp[i] = ways;
        }
        return dp[n];
    }
};
