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
    bool finded = 0;
    void dfs(TreeNode* root, int total, int target){
        if(finded || root==NULL){
            return;
        }
        total += root->val;
        if(root->left == NULL && root->right == NULL){
            if(total == target){
                finded = true;
            }
            else{
                return;   
            }
        }
        dfs(root->left, total, target);
        dfs(root->right, total, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        dfs(root, 0, targetSum);
        return finded;
    }
};