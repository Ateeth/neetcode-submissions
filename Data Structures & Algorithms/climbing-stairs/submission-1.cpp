class Solution {
public:
    int f(int idx, vector<int>& dp){
        if(idx < 0) return 0;
        if(idx == 0) return 1;

        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = f(idx-1, dp) + f(idx-2, dp);
    }
    int climbStairs(int n) {
        
        vector<int> dp(n + 1 , -1);
        return f(n , dp);
        // return climbStairs(n-1) + climbStairs(n-2);
    }
};
