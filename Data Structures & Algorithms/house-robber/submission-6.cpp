class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + f(idx - 2, nums, dp);
        int notTake = f(idx - 1, nums, dp);

        return dp[idx]= max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n , -1);
        // return f(n - 1, nums, dp);
        vector<int> dp(n , 0);
        dp[0]= nums[0];

        for(int i = 1 ; i < n ; ++i){
            int take = nums[i];
            if(i > 1){
                take += dp[i-2];
            }
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }
};
