class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        set<string> st(wordList.begin(), wordList.end());

        if(st.find(beginWord) != st.end()) st.erase(beginWord);

        while(!q.empty()){
            auto top = q.front();
            string word = top.first;
            int step = top.second;
            q.pop();

            if(word == endWord) return step;

            for(int k = 0 ; k < word.size() ; ++k){
                char ch = word[k];
                for(char i = 'a'; i <= 'z'; ++i){
                    word[k] = i;
                    if(st.find(word) != st.end()){
                        q.push({word, step + 1});
                        st.erase(word);
                    }
                }
                word[k] = ch;
            }
        }
        return 0;
    }
};
