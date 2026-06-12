class Solution {
public:
    const vector<string> phone = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> ans = f("", digits);
        return ans;
    }

    vector<string> f(string p, string up){
        vector<string> ans;

        if(up.length() == 0){
            vector<string> list;
            list.push_back(p);
            return list;
        }

        string letters = phone[up[0] - '0'];
        for(int i = 0; i < letters.size() ; ++i){
            vector<string> subList = f(p + letters[i], up.substr(1));
            ans.insert(ans.end(), subList.begin(), subList.end());
        }

        return ans;
    }
};
