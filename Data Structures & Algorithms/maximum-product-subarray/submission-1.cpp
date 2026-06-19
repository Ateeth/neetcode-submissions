class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1;
        int res = INT_MIN;
        for(int num : nums){
            res = max(res , num);
        }

        for(int n : nums){
            if(n == 0){
                currMax = 1;
                currMin = 1;        
            }

            int tmp = currMax * n;
            currMax = max(currMax * n, max(currMin * n, n));
            currMin = min(tmp, min(currMin * n, n));
            res = max(res, max(currMax, currMin));
        }

        return res;
        
    }
};
