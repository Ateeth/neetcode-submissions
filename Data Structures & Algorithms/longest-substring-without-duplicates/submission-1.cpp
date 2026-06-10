class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        set<char> st;
        int len = 0, maxLen = 0;
        while(r < s.size()){
            // new character
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxLen = max(maxLen, (int)st.size());
                ++r;
            }
            // duplicate has been found try removing character at left pointer move it ahead
            else {
                st.erase(s[l]);
                ++l;
           }
        }
        return maxLen;
    }
};
