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
        unordered_map<Node*, Node*> m{{node, new Node(node->val)}};
        queue<Node*> q{{node}};
        
        while(!q.empty()){
            auto u = q.front();  q.pop();
            for(auto v: u->neighbors){
                if(!m.count(v)){
                    m[v] = new Node(v->val);
                    q.push(v);
                }
                m[u]->neighbors.push_back(m[v]);
            }
        }
        return m[node];
    }
};