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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        set<int> used;
        for(auto d: descriptions){
            int fa = d[0], child = d[1], isLeft = d[2];
            if(!m.count(fa)){
                m[fa] = new TreeNode(fa);
            }
            if(!m.count(child)){
                m[child] = new TreeNode(child);
            }
            if(isLeft){
                m[fa]->left = m[child];
            }
            else{
                m[fa]->right = m[child];
            }
            used.insert(child);
        }
        for(auto node: m){
            int val = node.first;
            if(!used.count(val)){
                return node.second;
            }
        }
        return NULL;
    }
};