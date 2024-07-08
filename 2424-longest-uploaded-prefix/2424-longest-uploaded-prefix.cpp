class LUPrefix {
public:
    int prefix = 0;
    vector<bool> v;
    LUPrefix(int n) {
        v.resize(n + 5, false);
    }
    
    void upload(int video) {
        v[video] = true;
        while(v[prefix + 1] == true){
            prefix++;
        }
    }
    
    int longest() {
        return prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */