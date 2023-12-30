class SmallestInfiniteSet {
public:
    set<int>s;
    int curr = 1;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        s.insert(curr++);
        int ret = *s.begin();
        s.erase(ret);
        return ret;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */