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
    vector<int> G[(int)1e5 + 5];
    int used[(int)1e5 + 5] = {0};
    
    void build_graph(TreeNode* root){
        if(root->left){
            G[root->val].emplace_back(root->left->val);
            G[root->left->val].emplace_back(root->val);
            build_graph(root->left);
        }
        if(root->right){
            G[root->val].emplace_back(root->right->val);
            G[root->right->val].emplace_back(root->val);
            build_graph(root->right);
        }
    }
    int dfs(int u, int depth){
        used[u] = true;
        int max_depth = depth;
        for(auto v: G[u]){
            if(!used[v]){
                max_depth = max(max_depth, dfs(v, depth + 1));
            }
        }
        return max_depth;
    }
    int amountOfTime(TreeNode* root, int start) {
        build_graph(root);
        return dfs(start, 0);
    }
};