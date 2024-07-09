/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root){
            return {};
        }
        stack<Node*>s;
        s.emplace(root);
        vector<int> ans;
        while(!s.empty()){
            Node* now = s.top();  s.pop();
            ans.emplace_back(now->val);
            for(auto it = now->children.rbegin(); it < now->children.rend(); it++){
                s.emplace(*it);
            }
        }
        return ans;
    }
};