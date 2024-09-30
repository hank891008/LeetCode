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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> tmp;
            while(sz--){
                TreeNode* now = q.front();
                q.pop();
                tmp.emplace_back(now->val);
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
            }
            ans.emplace_back(tmp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};