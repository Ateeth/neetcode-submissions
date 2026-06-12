class Solution {
public:
    void f(vector<int>& subset, vector<bool>& freq, vector<vector<int>>& ans, vector<int>& nums){
        if(subset.size() == nums.size()){
            ans.push_back(subset);
            return;
        }

        for(int i = 0 ; i < nums.size(); ++i){
            if(!freq[i]){
                subset.push_back(nums[i]);
                freq[i] = true;
                f(subset, freq, ans, nums);
                freq[i] = false;
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> freq(n);
        vector<int> subset;
        vector<vector<int>> ans;
        f(subset, freq, ans, nums);
        return ans;
    }
};
