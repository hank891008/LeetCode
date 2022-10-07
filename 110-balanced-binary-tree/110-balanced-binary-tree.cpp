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
    int flag = 1;
    int dfs(TreeNode* root){
        if(!flag){
            return 0;
        }
        if(root == NULL){
            return 0;
        }
        int l = dfs(root->left), r = dfs(root->right);
        if(abs(r - l) > 1){
            flag = 0;
            return 0;
        }
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && flag;
    }
};