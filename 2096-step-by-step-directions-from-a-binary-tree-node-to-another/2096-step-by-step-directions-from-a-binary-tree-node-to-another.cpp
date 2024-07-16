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
    int cnt = 0;
    string path;
    TreeNode* LCA(TreeNode* root, int s, int d){
        if(!root){
            return NULL;
        }
        if(root->val == s || root->val == d){
            return root;
        }
        TreeNode* left = LCA(root->left, s, d);
        TreeNode* right = LCA(root->right, s, d);
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
    void findr(TreeNode* root, int d, string& curr){
        if(root->val == d){
            path = curr;
            return;
        }
        if(path != ""){
            return;
        }
        if(root->left){
            curr.push_back('L');
            findr(root->left, d, curr);
            curr.pop_back();
        }
        if(root->right){
            curr.push_back('R');
            findr(root->right, d, curr);
            curr.pop_back();
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* common_root = LCA(root, startValue, destValue);
        string ans;
        string curr;
        path.clear();
        findr(common_root, startValue, curr);
        ans.append(path.size(), 'U');
        curr.clear();
        path.clear();
        findr(common_root, destValue, curr);
        ans.append(path);
        return ans;
    }
};