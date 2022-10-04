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
    vector<string>ret;
    vector<int>now;
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        now.emplace_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            string str;
            for(int i = 0; i < now.size() - 1; i++){
                str += (to_string(now[i]) + "->");
            }
            str += to_string(now[now.size() - 1]);
            ret.emplace_back(str);
        }
        dfs(root->left);
        dfs(root->right);
        now.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ret;
    }
};