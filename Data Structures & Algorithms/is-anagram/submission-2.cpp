class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        // Space complexity: O(1)
        // Time complexity: O(n log n)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // int i = 0 ;
        // while(i < s.size()){
        //     if(s[i] != t[i]) return false;
        //     ++i;
        // }

        // return true;

        // space complexity: O(26)
        // Time complextity: O(n)
        // can use frequncy map or since we know 26 characters use an array of 26 size
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0 ; i < n; ++i){
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        for(int i = 0 ; i < 26; ++i){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};
