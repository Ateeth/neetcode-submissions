class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset, int idx){
        ans.push_back(subset);
        for(int i = idx ; i < nums.size() ; ++i){
            if(i > idx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            f(ans, nums, subset, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        f(ans, nums, subset, 0);
        return ans;
    }
};
