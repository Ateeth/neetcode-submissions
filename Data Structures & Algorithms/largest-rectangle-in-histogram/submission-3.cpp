class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //ht * (nse - pse - 1)
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        int nse , pse;
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() && heights[st.top()] > heights[i]){
                 int x = st.top();
                 st.pop();
                 int pse= st.empty() ? -1 : st.top();
                 nse = i;
                 ans = max(ans, heights[x] * (nse - pse - 1));
            }

            st.push(i); 
        }
        while(!st.empty()){
            nse = n;
            int element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            ans = max(ans, heights[element] * (nse - pse - 1));
        }
        return ans;
    }
};
