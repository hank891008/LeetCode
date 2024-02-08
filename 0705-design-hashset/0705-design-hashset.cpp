class MyHashSet {
public:
    bitset<1000005> hash;
    MyHashSet() {
        hash.reset();
    }
    
    void add(int key) {
        hash.set(key, 1);
    }
    
    void remove(int key) {
        hash.set(key, 0);
    }
    
    bool contains(int key) {
        return hash.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */