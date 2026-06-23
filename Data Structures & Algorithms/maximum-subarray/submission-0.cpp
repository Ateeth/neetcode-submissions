class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = nums[0];
        for(int num: nums){
            sum += num;
            maxSum = max(maxSum , sum);

            if(sum < 0){
                sum = 0 ;
            }

        }

        return maxSum;
    }
};
