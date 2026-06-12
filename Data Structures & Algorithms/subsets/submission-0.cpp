class Solution {
public:
    void f(int idx, vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        f(idx + 1, ans, subset, nums);
        subset.pop_back();
        f(idx + 1, ans, subset, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        f(0, ans, subset, nums);
        return ans;
    }
};
