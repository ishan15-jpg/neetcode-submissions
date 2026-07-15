class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);
    
        function<void(int)> bfs = [&](int node){
            queue<int> q;
            visited[node] = true;
            q.push(node);

            while(!q.empty()){
                int curr = q.front(); q.pop();
                for(const int neigh : adjList[curr]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        };
        

        int components = 0;
        for(int v=0; v<n; ++v){
            if(!visited[v]){
                bfs(v);
                ++components;
            }
        }

        return components;
    }
};
