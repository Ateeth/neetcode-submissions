class Meeting {
    public:
        int start;
        int end;
        Meeting(int s, int e){
            this->start = s;
            this->end = e;
        }
};
class Solution {
public:
    static  bool comp(Meeting m1, Meeting m2){
        return m1.end < m2.end;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<Meeting> meetings;
        int n = intervals.size();

        for(int i = 0 ; i < n ; ++i){
            Meeting m(intervals[i][0], intervals[i][1]);
            meetings.push_back(m);
        }

        sort(meetings.begin(), meetings.end(), comp);
        int cnt = 1;
        int lastEnd = meetings[0].end;

        // find number of overlapping intervals
        for(int i = 1 ; i < n ; ++i){
            if(meetings[i].start >= lastEnd){
                ++cnt;
                lastEnd = meetings[i].end;
            }
        }

        return n - cnt;
    }
};
