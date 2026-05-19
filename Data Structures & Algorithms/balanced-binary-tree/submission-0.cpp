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
    bool isBalanced(TreeNode* root) {
        function<pair<bool,int>(TreeNode*)> help = [&](TreeNode* root) -> pair<bool,int> {
            if(!root) return {true, 0};
            if(!root->left && !root->right) return {true, 1};

            pair<bool,int> leftSub = help(root->left);
            pair<bool,int> rightSub = help(root->right);

            bool isBalanced = leftSub.first && rightSub.first;
            int heightDiff = abs(leftSub.second - rightSub.second);

            if(heightDiff > 1) isBalanced = false;

            int nodes = max(leftSub.second, rightSub.second) + 1;

            return {isBalanced, nodes};
        };

        return help(root).first;
    }
};
