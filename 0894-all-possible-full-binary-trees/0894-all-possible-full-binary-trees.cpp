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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0){
            return {};
        }
        vector<vector<TreeNode*>>dp(n + 1);
        dp[1].emplace_back(new TreeNode());
        for(int now = 3; now <= n; now += 2){
            for(int i = 1; i <= now - 1; i += 2){
                int j = now - 1 - i;
                for(auto l: dp[i]){
                    for(auto r: dp[j]){
                        dp[now].emplace_back(new TreeNode(0, l, r));
                    }
                }
            }
        }
        return dp[n];
    }
};