class RLEIterator {
public:
    deque<pair<int, int>>dq;
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i += 2){
            if(encoding[i] != 0){
                dq.emplace_back(encoding[i], encoding[i + 1]);
            }
        }
    }
    
    int next(int n) {
        if(dq.empty()){
            return -1;
        }
        auto now = dq.front();   
        dq.pop_front();
        while(now.first < n){
            n -= now.first;
            if(dq.empty()){
                return -1;
            }
            now = dq.front();   
            dq.pop_front();
        }
        if(now.first > n){
            now.first -= n;
            dq.emplace_front(now);
        }
        return now.second;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */