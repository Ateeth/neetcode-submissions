class Solution {
public:
    string minWindow(string s, string t) {
        int startIndex = -1, r = 0, l = 0, m = s.size(), n= t.size(), len = INT_MAX;
        unordered_map<char, int> mpp;
        for(char ch : t){
            ++mpp[ch];
        }
        int cnt = 0;

        while(r < m){
            if(mpp[s[r]] > 0) ++cnt;
            --mpp[s[r]];

            while(cnt == n){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    startIndex = l;
                }

                ++mpp[s[l]];
                if(mpp[s[l]] > 0) --cnt;
                ++l;
            }
            ++r;
        }

        if(startIndex == -1) return "";
        return s.substr(startIndex, len);
    }
};
