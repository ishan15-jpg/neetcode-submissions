class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<pair<int,int>> q;

        visited[0] = true;
        q.push({0,-1});

        while(!q.empty()){
            auto [node,parent] = q.front(); q.pop();
            visited[node] = true;
            for(const int neigh : adjList[node]){
                if(neigh == parent) continue;
                if(visited[neigh]) return false;
                q.push({neigh,node});
            }
        } 

        for(int node=0; node<n; ++node)
        if(!visited[node]) return false;

        return true;
    }
};
