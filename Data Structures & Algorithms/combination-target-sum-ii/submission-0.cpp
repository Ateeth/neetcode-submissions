class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        f(ans, subset, candidates, target, 0);
        return ans;
    }

    void f(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int target, int idx){
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(subset);
            return;
        }
        for(int i = idx ; i < nums.size(); ++i){
            if(i > idx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            f(ans, subset, nums, target - nums[i], i + 1) ;
            subset.pop_back();
        }
    }
};
