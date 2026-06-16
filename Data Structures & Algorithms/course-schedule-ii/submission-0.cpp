class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int r = prerequisites.size();
        int c = prerequisites[0].size();

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }

        vector<int> ans;
        queue<int> q;
        for(int i = 0 ; i < numCourses ; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);

            for(int adjCourse : adj[course]){
                --indegree[adjCourse];
                if(indegree[adjCourse] == 0){
                    q.push(adjCourse);
                }
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};
