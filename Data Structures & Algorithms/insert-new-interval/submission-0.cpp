class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0 ;
        int n = intervals.size();

        // add intervals before new interval involving no overlap at all
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            ++i;
        }

        // handle insertion of new intevral
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        res.push_back(newInterval);

        // add remaining  non ioverlapping intervals
        while(i < n){
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};
