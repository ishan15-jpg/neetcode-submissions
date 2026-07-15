class DSU {
    vector<int> parent;
    vector<int> rank;

    public:

    DSU(int n){
        for(int i=0; i<n; ++i) this->parent.push_back(i);
        this->rank.resize(n,1);
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool union_set(int u, int v){
        int pu = find(u), pv = find(v);

        if(pu == pv) return false;

        if(rank[pv] > rank[pu]){
            int temp = pv;
            pv = pu;
            pu = temp;
        }

        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);

        for(const vector<int> edge : edges)
            if(dsu->union_set(edge[0],edge[1])) --n;

        return n;
    }
};
