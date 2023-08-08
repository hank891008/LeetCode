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
        map<int, TreeNode*> m;
        set<int>has_p;
        for(int i = 0; i < descriptions.size(); i++){
            int parent = descriptions[i][0], child = descriptions[i][1], is_l = descriptions[i][2];
            has_p.insert(child);
            if(!m.count(parent)){
                m[parent] = new TreeNode(parent);
            }
            if(!m.count(child)){
                m[child] = new TreeNode(child);
            }
            if(is_l){
                m[parent]->left = m[child];
            }
            else{
                m[parent]->right = m[child];
            }
        }
        for(int i = 0; i < descriptions.size(); i++){
            if(!has_p.count(descriptions[i][0])){
                return m[descriptions[i][0]];
            }
        }
        return m[0];
    }
};