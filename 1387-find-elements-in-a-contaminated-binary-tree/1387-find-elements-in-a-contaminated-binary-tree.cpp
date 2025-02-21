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
class FindElements {
public:
unordered_set<int> s;
    FindElements(TreeNode* root) {
        if(root){
            root->val = 0;
        }
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            TreeNode* now = q.front();  q.pop();
            s.insert(now->val);
            if(now->left){
                now->left->val = 2 * now->val + 1;
                q.emplace(now->left);
            }
            if(now->right){
                now->right->val = 2 * now->val + 2;
                q.emplace(now->right);
            }
        }
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */