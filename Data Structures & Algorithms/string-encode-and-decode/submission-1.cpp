class Solution {
public:

    string encode(vector<string>& strs) {
        // length of word + # + word
        string encodedString = "";
        for(string s : strs){
            encodedString += to_string(s.size()) + "#" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        int i = 0;
        cout<<s<<endl;
        vector<string> ans;
        // while(i < s.size() && ctr < 3){
        //     string str = s.substr(i + 2, i  + (s[i]-'0'));
        //     i += (s[i] - '0' + 2);
        //     ans.push_back(str);
        // }
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                ++j;
            }

            // int length = stoi(s.substr(i, i + j));
            int length = stoi(s.substr(i, j));

            // string str = s.substr(j + 1, j + 1 + length);
            string str = s.substr(j + 1, length);
            ans.push_back(str);
            i = j + 1 + length;
        }
        return ans;
    }
};
