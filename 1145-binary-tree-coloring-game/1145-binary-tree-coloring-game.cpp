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
    int cnt_node(TreeNode* root, int x, int &l, int &r){
        if(!root){
            return 0;
        }
        int _l = cnt_node(root->left, x, l, r);
        int _r = cnt_node(root->right, x, l, r);
        if(root->val == x){
            l = _l;
            r = _r;
        }
        return _l + _r + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int l, r;
        cnt_node(root, x, l, r);
        if(max(max(l, r), n - l - r - 1) > n / 2){
            return true;
        }
        return false;
    }
};