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
    void solve(TreeNode* root, int& tot){
        if(root->right){
            solve(root->right, tot);
        }
        root->val += tot;
        tot = root->val;
        if(root->left){
            solve(root->left, tot);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int tot = 0;
        solve(root, tot);
        return root;
    }
};