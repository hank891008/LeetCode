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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q{{root}};
        priority_queue<long long> pq;
        while(!q.empty()){
            int sz = q.size();
            long long tot = 0;
            while(sz--){
                TreeNode* now = q.front();  q.pop();
                tot += now->val;
                if(now->left){
                    q.emplace(now->left);
                }
                if(now->right){
                    q.emplace(now->right);
                }
            }
            pq.emplace(tot);
        }
        while(!pq.empty() && k-- > 0){
            if(k == 0){
                return pq.top();
            }
            pq.pop();
        }
        return -1;
    }
};