class Solution {
public:
    int f(int idx, vector<int>& coins, int amount){
        if(idx == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }

            return 1e9;
        }

        int take = 1e9;
        if(coins[idx] <= amount) take= 1 + f(idx, coins, amount- coins[idx]);
        int notTake = f(idx - 1, coins, amount);
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans =  f(n-1, coins, amount);
        return ans == 1e9 ? -1 : ans;
    }
};
