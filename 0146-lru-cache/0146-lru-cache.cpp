class LRUCache {
public:
    struct Node{
        int key, value;
        Node *prev = NULL, *next = NULL;
        Node(int key, int value):key(key), value(value){}
    };
    int cap = 0;
    Node *head, *tail;
    map<int, Node*> m;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void del_node(Node* now){
        Node* l = now->prev;
        Node* r = now->next;
        l->next = r;
        r->prev = l;
    }
    
    void add_node(Node* now){
        now->prev = head;
        now->next = head->next;
        
        head->next = now;
        now->next->prev = now;
    }
    
    int get(int key) {
        if(!m.count(key)){
            return -1;
        }
        Node* now = m[key];
        int val = now->value;
        
        del_node(now);
        add_node(now);
        return val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node* now = m[key];
            m.erase(key);
            del_node(now);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            del_node(tail->prev);
        }
        Node* now = new Node(key, value);
        add_node(now);
        m[key] = now;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */