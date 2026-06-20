class Solution {
public:
    int f(int idx, int canBuy, int cooldown, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(idx == prices.size()) return 0;

        if(dp[idx][canBuy][cooldown] != -1) return dp[idx][canBuy][cooldown]; 
        int profit = 0;
        if(canBuy){
           int buy = 0;
           if(cooldown == 0){
             buy = -prices[idx] + f(idx + 1, 0, 0, prices, dp);
           }
           return dp[idx][canBuy][cooldown] = max(buy, f(idx + 1, 1, 0, prices, dp));
        } else {
            return dp[idx][canBuy][cooldown] = max(f(idx + 1, 0, 0, prices, dp), prices[idx] + f(idx + 1, 1, 1, prices, dp));  
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int canBuy = 1;
        // int cooldown = 1;
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        // return f(0, canBuy, 0, prices, dp);

        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        for(int i = prices.size() - 1 ; i >= 0 ; --i){
            for(int buy = 0 ; buy < 2 ; ++buy){
                for(int cool = 0 ; cool < 2 ; ++cool){
                    if(buy){
                        int buyPrice = 0;
                        if(cool == 0){
                            buyPrice = -prices[i] + dp[i+1][0][0];
                        }
                        dp[i][buy][cool] = max(buyPrice, dp[i+1][1][0]);
                    } else {
                        dp[i][buy][cool] = max(dp[i+1][0][0], prices[i] + dp[i+1][1][1]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};
