class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> window(26, 0);
        vector<int> need(26, 0);

        for(char ch : s1){
            ++need[ch-'a'];
        }
        int r = 0;
        r = 0;
        while(r < n){
            ++window[s2[r] - 'a'];
            if(r >= m){
                --window[s2[r-m] - 'a'];
            }

            if(window == need) return true;
            ++r;
        }
        return false;
    }
};
