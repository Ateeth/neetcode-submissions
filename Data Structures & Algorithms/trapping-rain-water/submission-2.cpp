class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0 , r = height.size() - 1, rMax = 0, lMax = 0;
        int total = 0;
        while(l < r){
            if(height[l] < height[r]){
                if(lMax > height[l]){
                    total += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l = l + 1;
            } else {
                if(rMax > height[r]){
                    total += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r = r - 1;
            }
        }
        return total;
    }
};
