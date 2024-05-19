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
    set<TreeNode*> s;
    void dfs(TreeNode* root, TreeNode* pa){
        if(root){
            dfs(root->left, root);
            dfs(root->right, root);
            if((pa == NULL && !s.count(root)) || (!s.count(root->left) || !s.count(root->right))){
                ans++;
                s.insert(pa);
                s.insert(root);
                s.insert(root->left);
                s.insert(root->right);
            }
        }
        
    }
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right){
            return 1;
        }
        s.insert(NULL);
        dfs(root, NULL);
        return ans;
    }
};