class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        
        int l = 0 , r = n-1, res = 0;

        while(l < r){
            int w = r - l;
            res = max(res, w * min(heights[l], heights[r]));

            // width will definitely go down so mvoe to potentially bigger height
            if(heights[l] < heights[r]){
                ++l;
            } else {
                --r;
            }
        } 

        return res;
    }
};
