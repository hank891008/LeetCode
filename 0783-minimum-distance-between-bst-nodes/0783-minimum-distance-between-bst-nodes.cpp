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
    void dfs(TreeNode* root, vector<int>& v){
        if(!root){
            return;
        }
        dfs(root->left, v);
        v.emplace_back(root->val);
        dfs(root->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        dfs(root, v);
        int minn = v[1] - v[0];
        for(int i = 2; i < v.size(); i++){
            minn = min(minn, v[i] - v[i - 1]);
        }
        return minn;
    }
};