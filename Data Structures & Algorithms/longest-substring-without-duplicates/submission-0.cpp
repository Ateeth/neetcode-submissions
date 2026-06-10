class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        set<char> st;
        int len = 0, maxLen = 0;
        while(l <= r && r < s.size()){
            while(r < s.size() && st.size() == r - l){
                st.insert(s[r]);
                ++r;
            }
            maxLen = max(maxLen, (int)st.size());
            st.clear();
            ++l;
            r = l;
        }
        return maxLen;
    }
};
