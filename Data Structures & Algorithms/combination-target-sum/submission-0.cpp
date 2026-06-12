class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int target, int idx){
        if(target < 0) return;

        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(subset);
            }
            return;
        }

        subset.push_back(nums[idx]);
        f(ans, subset, nums, target - nums[idx], idx);
        subset.pop_back();
        f(ans, subset, nums, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        f(ans, subset, nums, target, 0);
        return ans;
    }
};
