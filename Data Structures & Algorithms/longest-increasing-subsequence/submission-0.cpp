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
        vector<vector<int>> dp(n, vector<int>(n + 1 , -1));
        return f(0, nums, -1, dp);
    }
};
