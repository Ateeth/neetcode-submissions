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

    int ceil(vector<int>& ans, int num){
        int s = 0, e = ans.size() - 1;
        while(s < e){
            int m = s + (e - s) / 2;
            if(num > ans[m]){
                s = m + 1;
            } else {
                e = m;
            }
        }

        return s;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1 , -1));
        // return f(0, nums, -1, dp);

        // vector<vector<int>> dp(n + 1, vector<int>(n+1,0));
        // for(int idx = n - 1; idx >= 0 ; --idx){
        //     for(int prev = idx - 1 ; prev >= -1; --prev){
        //         int take = 0;
        //         if(prev == -1 || nums[idx] > nums[prev]){
        //             take = 1 + dp[idx + 1][idx + 1];
        //         }
        //         int notTake = dp[idx + 1][prev + 1];
        //         dp[idx][prev + 1] = max(take, notTake);
        //     }
        // }
        // return dp[0][0];

        // vector<int> dp(n , 1);
        // int len = 1;
        // for(int i = 0 ; i < n ; ++i){
        //     for(int prev = 0 ; prev < i ; ++prev){
        //         if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1){
        //             dp[i] = dp[prev] + 1;
        //         }
        //     }
        //     len = max(len , dp[i]);
        // }
        // return len;

        vector<int> dp(n , 1);
        int len = 1;
        vector<int> ans;
        for(int i=  0 ; i < n ; ++i){
            if(ans.size() == 0 || nums[i] > ans[ans.size() - 1]){
                ans.push_back(nums[i]);
            } else {
                int idx = ceil(ans, nums[i]);
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};
