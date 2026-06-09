class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        
        int maxLen = 1;
        for(int num : st){
            int len = 1;
            if(st.contains(num - 1)){
                continue; 
            }

            int x = num;
            while(st.contains(x + 1)){
                ++len;
                ++x;
            }
                maxLen = max(maxLen, len);

        }

        return maxLen;
    }
};
