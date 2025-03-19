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
    int ans[4];
    void dfs(TreeNode* root, int x, int y, int fa, int d){
        if(root->val == x){
            ans[0] = fa;
            ans[1] = d;
        }
        if(root->val == y){
            ans[2] = fa;
            ans[3] = d;
        }
        if(root->left){
            dfs(root->left, x, y, root->val, d + 1);
        }
        if(root->right){
            dfs(root->right, x, y, root->val, d + 1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, -1, 0);
        return (ans[0] != ans[2]) && (ans[1] == ans[3]);
    }
};