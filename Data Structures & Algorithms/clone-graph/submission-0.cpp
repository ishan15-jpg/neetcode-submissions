/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;

        function<Node*(Node*)> dfs = [&](Node* node) -> Node* {
            if(!node) return nullptr;
            if(mp.find(node) != mp.end()) return mp[node];

            Node* clone = new Node(node->val);
            mp[node] = clone;

            for(Node* neigh : node->neighbors){
                clone->neighbors.push_back(dfs(neigh));
            }

            return clone;
        };

        return dfs(node);
    }
};
