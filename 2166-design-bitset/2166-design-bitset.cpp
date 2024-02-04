class Bitset {
public:
    bool bit[100005];
    int si;
    int cnt;
    int f;
    Bitset(int size) {
        memset(bit, 0, sizeof(bit));
        si = size;
        cnt = 0;
        f = 0;
    }
    
    void fix(int idx) {
        if(f){ 
            if(bit[idx] == 1){
                bit[idx] = 0;
                cnt++;
            }
        }
        else{
            if(bit[idx] == 0){
                bit[idx] = 1;
                cnt++;
            }
        }
    }
    
    void unfix(int idx) {
        if(f){ 
            if(bit[idx] == 0){
                bit[idx] = 1;
                cnt--;
            }
        }
        else{
            if(bit[idx] == 1){
                bit[idx] = 0;
                cnt--;
            }
        }
    }
    
    void flip() {
        f = 1 - f;
        cnt = si - cnt;
    }
    
    bool all() {
        return cnt == si;
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string st;
        for(int i = 0; i < si; i++){
            if(f){
                bit[i] = 1 - bit[i];
            }
            st += ('0' + bit[i]);
        }
        f = 0;
        return st;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */