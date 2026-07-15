class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);

        function<void(int)> dfs = [&](int node){
            visited[node] = true;

            for(const int neigh : adjList[node]){
                if(!visited[neigh]) dfs(neigh);
            }
        };

        int components = 0;
        for(int v=0; v<n; ++v){
            if(!visited[v]){
                dfs(v);
                ++components;
            }
        }

        return components;
    }
};
