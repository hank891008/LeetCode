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
    int ans = 0;
    void dfs(TreeNode* root, vector<long long>& now, int target){
        if(root->val == target){
            ans++;
        }
        for(int i = 0; i < now.size(); i++){
            if(now[i] + root->val == target){
                ans++;
            }
            now[i] += root->val;
        }
        now.emplace_back(root->val);
        if(root->left){
            dfs(root->left, now, target);
        }
        if(root->right){
            dfs(root->right, now, target);
        }
        for(int i = 0; i < now.size(); i++){
            now[i] -= root->val;
        }
        now.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        vector<long long> now;
        dfs(root, now, targetSum);
        return ans;
    }
};