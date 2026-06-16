class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto &e : prerequisites ){
            adj[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses ; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int ctr = 0 ;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            ++ctr;
            for(int adjCourse : adj[course]){
                --indegree[adjCourse];
                if(indegree[adjCourse] == 0){
                    q.push(adjCourse);
                }
            }
        }

        return ctr == numCourses ? true : false;
    }
};
