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
class BSTIterator {
public:
    queue<int> q;
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        dfs(root->left);
        q.emplace(root->val);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        auto now = q.front();   q.pop();
        return now;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */