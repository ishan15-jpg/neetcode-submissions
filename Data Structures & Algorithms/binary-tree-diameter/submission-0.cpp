/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        function<pair<int,int>(TreeNode*)> help = [&](TreeNode* root) -> pair<int,int>{
            if(!root) return {0,0};
            if(!root->left && !root->right) return {0,1};

            pair<int,int> leftSub = help(root->left);
            pair<int,int> rightSub = help(root->right);

            int diameter = max(leftSub.second + rightSub.second, max(leftSub.first,rightSub.first));
            int nodes = max(leftSub.second, rightSub.second) + 1;

            return {diameter, nodes};
        };

        return help(root).first;
    }
};
