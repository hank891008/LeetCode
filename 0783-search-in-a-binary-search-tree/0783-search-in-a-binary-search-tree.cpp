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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            TreeNode* now = q.front();  q.pop();
            if(now->val == val){
                return now;
            }
            if(now->left){
                q.emplace(now->left);
            }
            if(now->right){
                q.emplace(now->right);
            }
        }
        return nullptr;
    }
};