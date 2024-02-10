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
    int ans = INT_MAX;
    void dfs(TreeNode* root, int depth){
        if(!root->left && !root->right){
            ans = min(ans, depth);
            return;
        }
        if(root->left){
            dfs(root->left, depth + 1);
        }
        if(root->right){
            dfs(root->right, depth + 1);
        }
    }
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root, 1);
        return ans;
    }
};