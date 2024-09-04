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
    long long a = LLONG_MAX - 1, b = LLONG_MAX;
    int findSecondMinimumValue(TreeNode* root) {
        if(!root){
            return -1;
        }
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            TreeNode* now = q.front();  q.pop();
            if(now->val < a){
                b = a;
                a = now->val;
            }
            else if(now->val < b && now->val > a){
                b = now->val;
            }
            if(now->left){
                q.emplace(now->left);
            }
            if(now->right){
                q.emplace(now->right);
            }
        }
        if((b != LLONG_MAX) && (b != LLONG_MAX - 1)){
            return b;
        }
        return -1;
    }
};