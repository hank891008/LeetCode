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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int maxx = INT_MIN;
        int max_level = -1;
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            level++;
            while(sz--){
                TreeNode* now = q.front();  q.pop();
                sum += now->val;
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
            }
            if(sum > maxx){
                maxx = sum;
                max_level = level;
            }
        }
        return max_level;
    }
};