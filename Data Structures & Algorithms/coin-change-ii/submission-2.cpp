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
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // return f(amount, n - 1, coins, dp);

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i = 0 ; i <= amount ; ++i){
            if(i % coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int i = 1 ; i < n ; ++i){
            for(int amt = 0 ; amt <= amount ; ++amt){
                int take = 0;
                if(coins[i] <= amt){
                    take = dp[i][amt - coins[i]];
                }
                int notTake = dp[i-1][amt];
                dp[i][amt] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};
