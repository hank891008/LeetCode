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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            int sz = q.size();
            TreeNode* now;
            while(sz--){
                now = q.front();
                q.pop();
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
            }
            ans.emplace_back(now->val);
        }
        return ans;
    }
};