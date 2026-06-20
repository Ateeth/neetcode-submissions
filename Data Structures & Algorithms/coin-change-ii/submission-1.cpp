class Solution {
public:
    int f(int amount, int idx, vector<int>& coins, vector<vector<int>>& dp){
        if(idx == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int take = 0 ;
        if(coins[idx] <= amount){
            take = f(amount - coins[idx], idx, coins, dp);
        }
        int notTake = f(amount, idx - 1, coins, dp);
        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(amount, n - 1, coins, dp);
    }
};
