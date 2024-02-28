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
    int findBottomLeftValue(TreeNode* root) {
        int first;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            first = q.front()->val;
            int si = q.size();
            while(si--){
                TreeNode* now = q.front();
                q.pop();
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
            }
        }
        return first;
    }
};