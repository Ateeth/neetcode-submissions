class Solution {
public:
    bool f(int idx, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0){
            return target == 0 || nums[0] == target;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        bool take = false;
        if(nums[idx] <= target){
            take = f(idx - 1 , nums, target - nums[idx], dp);
        }

        bool notTake = f(idx - 1, nums, target, dp);

        return dp[idx][target]  = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0 ;
        for(int num :  nums){
            totalSum += num;
        }

        if(totalSum % 2 == 1) return false;
        int target = totalSum / 2;

        vector<vector<int>> dp(n , vector<int>(target + 1, -1));
        return f(n-1, nums, target, dp);
    }
};
