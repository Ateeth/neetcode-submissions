class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> product(n);
        product[0] = 1;
        for(int i = 1 ; i < n ; ++i){
            product[i] = product[i-1] * nums[i-1];
        }
        int x = 1;
        for(int i = n-2 ; i >= 0 ; --i){
            x = x * nums[i+1];
            product[i] *= x;
        }

        return product;
    }
};
