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
        // vector<vector<int>> dp(n, vector<int>(amount + 1,-1));
        // int ans =  f(n-1, coins, amount, dp);
        // return ans == 1e9 ? -1 : ans;

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i = 0 ; i <= amount ; ++i){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }

        for(int i = 1; i < n ; ++i){
            for(int amt = 0 ; amt <= amount ; ++amt){
                int take = 1e9;
                if(coins[i] <= amt){
                    take = 1 + dp[i][amt-coins[i]];
                }
                int notTake = dp[i-1][amt];
                dp[i][amt] = min(take, notTake);
            }
        }

        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};
