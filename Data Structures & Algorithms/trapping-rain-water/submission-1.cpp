class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = height[0], rMax = height[n-1];
        int res = 0 ;
        int l = 0 , r=n-1;
        while(l < r){
            if(lMax < rMax){
                ++l;
                lMax = max(lMax, height[l]); 

                if(lMax - height[l] > 0){
                    res += lMax - height[l];
                }
            } else {
                --r;
                rMax = max(rMax , height[r]);

                if(rMax - height[r] > 0){
                    res += rMax - height[r];
                }
            }
        }

        return res;
    }
};
