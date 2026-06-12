class Solution {
public:
    void f(vector<string>& ans, string& s, int no, int nc, int n){
        if(no == nc && no == n){
            ans.push_back(s);
            return;
        }

        if(no < n){
            s += "(";
            f(ans, s, no+ 1, nc, n);
            s = s.substr(0, s.size()-1);
        }

        if(nc < no){
            s += ")";
            f(ans, s, no, nc + 1, n);
            s = s.substr(0, s.size()-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        f(ans, s, 0, 0, n);
        return ans;
    }
};
