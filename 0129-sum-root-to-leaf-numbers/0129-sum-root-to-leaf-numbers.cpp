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
    int ans = 0;
    void dfs(TreeNode* root, int tot){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            ans += 10 * tot + root->val;
        }
        dfs(root->left, 10 * tot + root->val);
        dfs(root->right, 10 * tot + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root, 0);
        return ans;
    }
};