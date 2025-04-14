// Leetcode Premium - not entirely sure this runs
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
    TreeNode* dfs(TreeNode *node, vector<int>& leaves) {
        if(node ==nullptr)
            return nullptr;
        if(node->left ==nullptr && node->right== nullptr){
            leaves.push_back(node->val);
            // node = nullptr; // this doesn't modify the actual value because it is a copy!!
            return nullptr;
        }

        node->left = dfs(node->left, leaves);
        node->right = dfs(node->right, leaves);

        return node;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        while(root != nullptr) {
            vector<int> leaves;
            dfs(root, leaves);
            ret.push_back(leaves);
        }
        return ret;
    }
};
