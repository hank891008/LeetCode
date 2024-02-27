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
    int dfs(TreeNode* root, int tot){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 10 * tot + root->val;
        }
        return dfs(root->left, 10 * tot + root->val) + dfs(root->right, 10 * tot + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        return dfs(root, 0);
    }
};