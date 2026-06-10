class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int small_left = INT_MAX;
        int res = 0;

        for(int i = 1; i < n ; ++i){
            small_left = min(small_left, nums[i-1]);
            res = max(res, nums[i] - small_left);
        }

        return res;
    }
};
