class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0 , r = 0 , len = 0;
        unordered_set<char> st;
        while(r < n){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                ++r;
                len = max(len, r - l);
            } else {
                st.erase(s[l]);
                ++l;
            }
        }
        return len;
    }
};
