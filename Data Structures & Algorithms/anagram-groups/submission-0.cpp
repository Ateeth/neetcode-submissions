class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(int i = 0 ; i < strs.size(); ++i){
            string key = strs[i];
            sort(key.begin(), key.end());
            if(mpp.find(key) != mpp.end()){
                mpp[key].push_back(strs[i]);
            } else {
                mpp[key] = {strs[i]};
            }
        }

        vector<vector<string>> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
