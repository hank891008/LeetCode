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
    int tot = 0;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = dfs(root->left), r = dfs(root->right);
        tot += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return tot;
    }
};