class Solution {
public:
    int f(int idx, vector<int>& nums, int prev, vector<vector<int>>& dp){
        if(idx == nums.size()) return 0;

        if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1 + f(idx + 1, nums, idx, dp);
        }
        int notTake = f(idx + 1, nums, prev, dp);
        return dp[idx][prev + 1] =  max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1 , -1));
        // return f(0, nums, -1, dp);

        vector<vector<int>> dp(n + 1, vector<int>(n+1,0));
        for(int idx = n - 1; idx >= 0 ; --idx){
            for(int prev = idx - 1 ; prev >= -1; --prev){
                int take = 0;
                if(prev == -1 || nums[idx] > nums[prev]){
                    take = 1 + dp[idx + 1][idx + 1];
                }
                int notTake = dp[idx + 1][prev + 1];
                dp[idx][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];

    }
};
