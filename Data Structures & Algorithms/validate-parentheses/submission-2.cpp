class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.size() ; ++i){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }

            else if(!st.empty() && ch == ')' && st.top() == '(' ) st.pop();
            else if(!st.empty() && ch == ']' && st.top() == '[') st.pop();
            else if(!st.empty() && ch == '}' && st.top() == '{') st.pop();
            else return false;
        }
        return st.empty() ? true : false;
    }
};
