class Solution {
public:
    int f(vector<int>& nums, int idx, int target, vector<vector<int>>& dp){
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int take = 0;
        if(nums[idx] <= target)
            take = f(nums, idx - 1, target - nums[idx], dp);

        int notTake = f(nums, idx - 1, target, dp);

        return dp[idx][target]  = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for(int x : nums)
            total += x;

        if(abs(target) > total) return 0;

        if((total + target) % 2 != 0) return 0;

        int targetSum = (total + target) / 2;
        // vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1 , -1));
        // return f(nums, nums.size() - 1, targetSum, dp);


        vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1 , 0));
        if(nums[0] == 0){
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
        }

        if(nums[0] != 0 && nums[0] <= targetSum) dp[0][nums[0]] = 1;

        for(int i = 1 ; i < nums.size() ; ++i){
            for(int t = 0 ; t <= targetSum ; ++t){
                int take = 0;
                if(nums[i] <= t)
                    take = dp[i-1][t - nums[i]];

                int notTake = dp[i-1][t];
                dp[i][t] = take + notTake;
            }
        }
        return dp[nums.size() - 1][targetSum];
    }
};