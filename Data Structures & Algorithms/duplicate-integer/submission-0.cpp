class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mpp;
        for(int num: nums){
            if(mpp.find(num) == mpp.end()){
                mpp[num] = true;
            } else {
                return true;
            }
        }
        return false;
    }
};