class Solution {
public:
    int f(int idx, vector<int>& cost, vector<int>& dp){
        if(idx < 0) return 0;
        if(idx < 2) return cost[idx];
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(f(idx - 1, cost, dp) , f(idx - 2, cost, dp));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n, -1);
        // return min(f(n - 1, cost, dp), f(n-2, cost, dp));

        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; ++i){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
