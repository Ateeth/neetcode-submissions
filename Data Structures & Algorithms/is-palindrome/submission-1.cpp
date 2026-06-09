class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        for(char ch : s){
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <='9')){
                str += tolower(ch);
            }
        }
        // if(str == "") return false;
        int i = 0, j = str.size() - 1;
        while(i <= j){
            if(str[i] != str[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};
