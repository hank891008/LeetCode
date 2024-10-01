/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        Node* node2 = new Node(node->val);
        map<int, Node*> m;
        m[node->val] = node2;
        queue<pair<Node*, Node*>> q;
        q.push({node, node2});
        
        while(!q.empty()){
            auto [u, u2] = q.front();  q.pop();
            if(u2->neighbors.size() != 0){
                continue;
            }
            for(auto v: u->neighbors){
                if(!m.count(v->val)){
                    m[v->val] = new Node(v->val);
                }
                u2->neighbors.push_back(m[v->val]);
                q.push({v, m[v->val]});
            }
        }
        return node2;
    }
};