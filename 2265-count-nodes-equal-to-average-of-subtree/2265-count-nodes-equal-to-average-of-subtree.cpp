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
    // sum, node count
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        if(sum / cnt == root->val){
            ans++;
        }
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};