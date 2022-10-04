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
    vector<vector<int>> ans;
    vector<int>now;
    void dfs(TreeNode* root, int tot, int target){
        if(root == NULL){
            return;
        }
        tot += root->val;
        now.emplace_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(tot == target){
                ans.emplace_back(now);
            }
        }
        dfs(root->left, tot, target);
        dfs(root->right, tot, target);
        now.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return ans;
        }
        dfs(root, 0, targetSum);
        return ans;
    }
};