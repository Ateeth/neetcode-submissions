class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lh(n);
        vector<int> rh(n);

        // get max height towards left
        lh[0] = height[0];
        for(int i = 1; i < n ; ++i){
            lh[i] = max(height[i], lh[i-1]);
        }

        // get max height towards right
        rh[n-1] = height[n-1];
        for(int i = n - 2 ; i >= 0 ; --i){
            rh[i]= max(height[i], rh[i+1]);
        }

        int res = 0 ;
        for(int i = 0 ; i < n ; ++i){
            res += min(lh[i], rh[i]) - height[i];
        }

        return res;
    }
};
