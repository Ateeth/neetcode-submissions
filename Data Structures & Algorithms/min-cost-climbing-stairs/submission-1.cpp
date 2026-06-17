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
        vector<int> dp(n, -1);
        return min(f(n - 1, cost, dp), f(n-2, cost, dp));
    }
};
