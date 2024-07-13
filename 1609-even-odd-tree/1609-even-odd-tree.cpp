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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int odd = false;
        while(!q.empty()){
            int n = q.size();
            int left;
            if(odd){
                left = INT_MAX;
            }
            else{
                left = INT_MIN;
            }
            while(n--){
                TreeNode* now = q.front();    q.pop();
                if(odd && now->val % 2 == 0 && now->val < left){
                    left = now->val;
                }
                else if(!odd && now->val % 2 == 1 && now->val > left){
                    left = now->val;
                }
                else{
                    return false;
                }
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
                
            }
            odd ^= 1;
        }
        return true;
    }
};