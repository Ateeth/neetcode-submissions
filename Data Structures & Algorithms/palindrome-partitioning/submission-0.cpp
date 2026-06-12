class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        solve(0, res, path, s);
        return res;
    }

    void solve(int idx, vector<vector<string>>& res, vector<string>& path, string s){
        if(idx == s.size()){
            res.push_back(path);
            return;
        }

        for(int i = idx; i < s.size() ; ++i){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, res, path, s);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};
