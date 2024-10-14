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
    void inorder(TreeNode* root, vector<int>& v){
        if(!root){
            return;
        }
        inorder(root->left, v);
        v.emplace_back(root->val);
        inorder(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int diff = v[1] - v[0];
        for(int i = 2; i < v.size(); i++){
            diff = min(diff, v[i] - v[i - 1]);
        }
        return diff;
    }
};