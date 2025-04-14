/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string dfs(TreeNode* node, int val, string& path) {
        if (node == nullptr)
            return "";

        if (node->val == val)
            return path;

        path.push_back('L');
        string res = dfs(node->left, val, path);
        if (!res.empty())
            return res;
        path.pop_back();

        path.push_back('R');
        res = dfs(node->right, val, path);
        if (!res.empty())
            return res;
        path.pop_back();
        return "";
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path_s = "";
        dfs(root, startValue, path_s);
        string path_d = "";
        dfs(root, destValue, path_d);

        int slen = path_s.length();
        int dlen = path_d.length();

        int i = 0;
        for (; i < slen && i < dlen; ++i) {
            if (path_s[i] != path_d[i])
                break;
        }

        string ret = "";
        for (int j = i; j < slen; ++j)
            ret += "U";

        ret += path_d.substr(i);

        return ret;
    }
};