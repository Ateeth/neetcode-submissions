class Solution {
public:
    int f(vector<int>& nums, int idx, int target){
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }

        int take = 0;
        if(nums[idx] <= target)
            take = f(nums, idx - 1, target - nums[idx]);

        int notTake = f(nums, idx - 1, target);

        return take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for(int x : nums)
            total += x;

        if(abs(target) > total) return 0;

        if((total + target) % 2 != 0) return 0;

        int targetSum = (total + target) / 2;

        return f(nums, nums.size() - 1, targetSum);
    }
};