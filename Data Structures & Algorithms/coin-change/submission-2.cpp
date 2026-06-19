class Solution {
public:
    int f(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(idx == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }

            return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = 1e9;
        if(coins[idx] <= amount) take= 1 + f(idx, coins, amount- coins[idx], dp);
        int notTake = f(idx - 1, coins, amount, dp);
        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1,-1));
        int ans =  f(n-1, coins, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
