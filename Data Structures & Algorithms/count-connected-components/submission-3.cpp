class DSU {

    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

        DSU(int n){
            rank.resize(n , 0);
            size.resize(n , 1);
            parent.resize(n);

            for(int i = 0 ; i < n ; ++i){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(parent[node] == node) return node;

            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(size[pu] > size[pv]){
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }

        void unionByRank(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            } else if(rank[pv] > rank[pu]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                ++rank[pu];
            }
        }
};

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> adj(n);
        // int ctr = 0;
        // for(auto &e : edges){
        //     adj[e[0]].push_back(e[1]);
        //     adj[e[1]].push_back(e[0]);
        // }

        // vector<int> vis(n, 0);


        // for(int i = 0 ; i < n ; ++i){
        //     if(!vis[i]){
        //         dfs(i, adj, vis);
        //         ++ctr;
        //     }
        // }

        // return ctr;

        int components = n;
        DSU dsu(n);
        for(auto& e : edges){
            if(dsu.findParent(e[0]) != dsu.findParent(e[1])){
                // dsu.unionBySize(e[0],e[1]);
                dsu.unionByRank(e[0],e[1]);
                --components;
            }
        }
        return components;
    }
};
