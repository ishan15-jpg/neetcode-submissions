class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        function<bool(int,int)> dfs = [&](int node,int parent) -> bool {
            visited[node] = true;
            for(const int neigh : adjList[node]){
                if(neigh != parent && visited[neigh]) return true;
                if(!visited[neigh] && dfs(neigh,node)) return true;
            }
            return false;
        };

       if(dfs(0,-1)) return false;

       for(int node=0; node<n; ++node)
       if(!visited[node]) return false;

        return true;
    }
};
