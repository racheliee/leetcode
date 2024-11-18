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
    int recur(TreeNode* node, int& cnt, int k){
        if(node == nullptr) return -1;

        // search left
        int left = recur(node->left, cnt, k);

        if(left != -1) return left;

        // current node is the kth
        if(++cnt == k)
            return node->val;
        
        // search right
        int right = recur(node->right, cnt, k);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return recur(root, cnt, k);
    }
};