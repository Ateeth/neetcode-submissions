class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            size.resize(n, 1);

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
            } else if(rank[pv] > rank[pu]){
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                ++rank[pv];
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DSU dsu(edges.size());

        for(auto& e : edges){
            if(dsu.findParent(e[0] - 1) == dsu.findParent(e[1] - 1)) return {e[0], e[1]};
            // dsu.unionBySize(e[0] - 1, e[1] - 1);
            dsu.unionByRank(e[0] - 1 , e[1] - 1);
        }

        return {};
    }
};
