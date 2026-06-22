class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> arr;
        for(int i = 0 ; i < n ; ++i){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end());
        vector<double> st;

        for(int i = n - 1 ; i >= 0 ; --i){
            double time = ((double)(target - arr[i].first) / arr[i].second);
            st.push_back(time);

            if(st.size() >= 2 && st[st.size() - 1] <= st[st.size() - 2]){
                st.pop_back();
            }
        }

        return st.size();
    }
};
