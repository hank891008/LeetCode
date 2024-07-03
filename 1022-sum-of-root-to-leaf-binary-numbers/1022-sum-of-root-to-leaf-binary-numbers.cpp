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
    int ans;
    vector<int> now;
    int bin2int(){
        int tot = 0;
        for(auto n: now){
            tot <<= 1;
            tot += n;
        }
        return tot;
    }
    void dfs(TreeNode* root){
        now.emplace_back(root->val);
        if(root->left){
            dfs(root->left);
        }
        if(root->right){
            dfs(root->right);
        }
        if(!root->left && !root->right){
            ans += bin2int();
        }
        now.pop_back();
        
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};