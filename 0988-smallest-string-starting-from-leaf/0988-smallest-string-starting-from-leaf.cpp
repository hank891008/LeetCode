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
    void dfs(TreeNode* root, string now, vector<string>& all){
        if(!root->left && !root->right){
            all.emplace_back(now + char('a' + root->val));
            reverse(all.back().begin(), all.back().end());
        }
        if(root->left){
            dfs(root->left, now + char('a' + root->val), all);
        }
        if(root->right){
            dfs(root->right, now + char('a' + root->val), all);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> all;
        dfs(root, "", all);
        sort(all.begin(), all.end());
        return all[0];
    }
};