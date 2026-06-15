class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int len = 0, n = s.size(), l = 0, r = 0;
        int maxFreq = 0;

        while(r < n){
            ++mpp[s[r]];
            maxFreq = max(maxFreq, mpp[s[r]]);

            if(r - l + 1 - maxFreq > k){
                --mpp[s[l]];
                ++l;
            }
            if(r - l + 1 - maxFreq <= k){
                len = max(len , r - l + 1);
            }
            ++r;
        }

        return len;
    }
};
