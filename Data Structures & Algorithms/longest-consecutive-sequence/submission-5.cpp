class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> st;
        for(int num: nums){
            st.insert(num);
        }

        int maxLen = 1;
        for(int num : st){
            int x = num;
            int len = 1;
            if(st.contains(x-1)) continue;
            while(st.contains(x + 1)){
                x = x + 1;
                ++len;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
