class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // get the frequency of each element in map
        unordered_map<int, int> mpp;
        for(int num : nums){
            if(mpp.find(num) != mpp.end()){
                ++mpp[num];
            } else {
                mpp[num] = 1;
            }
        }

        // keep adding elements in a heap and maintain size of k, add elemetns with frequency first in pair
        priority_queue <
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for(auto it : mpp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        // remove elements from heap and add to ans
        vector<int> ans;
        while(pq.size() != 0){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }

        return ans;
    }
};
