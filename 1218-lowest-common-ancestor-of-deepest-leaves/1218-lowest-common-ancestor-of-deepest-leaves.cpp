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
    int maxx = 0;
    TreeNode* ans;
    int dfs(TreeNode* root, int depth){
        maxx = max(maxx, depth);
        int left = (root->left) ? dfs(root->left, depth + 1) : depth;
        int right = (root->right) ? dfs(root->right, depth + 1) : depth;
        if(left == right && left == maxx){
            ans = root;
        }
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};