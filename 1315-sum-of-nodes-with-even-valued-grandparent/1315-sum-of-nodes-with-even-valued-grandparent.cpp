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
    int solve(TreeNode* root, int pa = -1, int gpa = -1){
        if(!root){
            return 0;
        }
        int ans = 0;
        ans += solve(root->left, root->val, pa);
        ans += solve(root->right, root->val, pa);
        if(gpa % 2 == 0){
            ans += root->val;
        }
        return ans;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root);
    }
};