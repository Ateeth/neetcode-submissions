class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0 ;
        int l = 0 , r = n - 1;

        while(l < r){
            int w = r - l;
            int h = min(heights[l], heights[r]);
            res = max(res, w * h);

            if(heights[l] < heights[r]) ++l;
            else --r;
        }
        return res;
    }
};
