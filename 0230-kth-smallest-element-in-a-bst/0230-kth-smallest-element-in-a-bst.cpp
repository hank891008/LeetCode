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
    int cnt = 0, ans = -1;
    void dfs(TreeNode* root, int k){
        if(ans != -1){
            return;
        }
        if(root->left){
            dfs(root->left, k);
        }
        if(++cnt == k){
            ans = root->val;
        }
        if(root->right){
            dfs(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};