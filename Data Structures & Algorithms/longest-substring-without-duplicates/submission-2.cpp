class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        set<char> st;
        int len = 0, maxLen = 0;
        while(r < s.size()){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxLen = max(maxLen , r - l + 1);
                ++r;
            } else {
                st.erase(s[l]);
                ++l;
            }
        }
        return maxLen;
    }
};
