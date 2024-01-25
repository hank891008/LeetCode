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
    int dfs(TreeNode* root, int minn, int maxx){
        int diff = max(abs(root->val - maxx), abs(root->val - minn));
        minn = min(minn, root->val);
        maxx = max(maxx, root->val);
        if(root->left){
            diff = max(diff, dfs(root->left, minn, maxx));
        }
        if(root->right){
            diff = max(diff, dfs(root->right, minn, maxx));
        }
        return diff;
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};