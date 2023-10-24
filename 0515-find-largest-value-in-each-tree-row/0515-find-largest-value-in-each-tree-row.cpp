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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.emplace(root);
        while(!q.empty()){
            int cnt = q.size();
            ans.emplace_back(INT_MIN);
            while(cnt--){
                auto now = q.front();   q.pop();
                if(ans.back() < now->val){
                    ans.pop_back();
                    ans.emplace_back(now->val);
                }
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
            }
        }
        return ans;
    }
};