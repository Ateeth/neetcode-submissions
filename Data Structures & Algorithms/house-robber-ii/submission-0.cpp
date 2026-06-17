class Solution {
public:
    int money(int idx, vector<int>& arr, vector<int>& dp){
        if(idx < 0) return 0;
        if(idx == 0) return arr[0];
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(arr[idx] + money(idx-2, arr, dp), money(idx - 1, arr, dp));
    }
    
    int hr(vector<int>& arr){
        int n = arr.size();
        if(n == 1) return arr[0];
        // vector<int> dp(n, -1);
        // return money(n-1, arr, dp);

        vector<int> dp(n, 0);
        int prev2 = 0;
        int prev = arr[0];
        for(int i = 1; i < n; ++i){
            int pick = arr[i];
            if(i > 1){
                pick += prev2;
            }
            int notPick = prev;

            dp[i] = max(pick, notPick);
            prev2 = prev;
            prev = dp[i];
        }

        return dp[n-1];

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;

        for(int i = 0 ; i < n ; ++i){
            if(i != 0) temp2.push_back(nums[i]);
            if(i != n-1) temp1.push_back(nums[i]);
        }

        return max(hr(temp1), hr(temp2));
    }
};