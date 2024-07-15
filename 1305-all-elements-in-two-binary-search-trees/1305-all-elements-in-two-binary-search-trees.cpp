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
    void dfs(TreeNode* root, vector<int>& v){
        if(!root){
            return;
        }
        if(root->left){
            dfs(root->left, v);
        }
        v.emplace_back(root->val);
        if(root->right){
            dfs(root->right, v);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        vector<int> ans;
        dfs(root1, v1);
        dfs(root2, v2);
        int i = 0, j = 0;
        while(i < v1.size() || j < v2.size()){
            if(i == v1.size()){
                ans.emplace_back(v2[j++]);
            }
            else if(j == v2.size()){
                ans.emplace_back(v1[i++]);
            }
            else if(v1[i] <= v2[j]){
                ans.emplace_back(v1[i++]);
            }
            else{
                ans.emplace_back(v2[j++]);
            }
        }
        return ans;
    }
};