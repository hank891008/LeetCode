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
        if(root->left){
            dfs(root->left, v);
        }
        v.emplace_back(root->val);
        if(root->right){
            dfs(root->right, v);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        for(int i = 1; i < v.size(); i++){
            if(v[i - 1] >= v[i]){
                return false;
            }
        }
        return true;
    }
};