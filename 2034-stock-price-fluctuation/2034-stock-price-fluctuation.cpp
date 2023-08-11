class StockPrice {
private:
    map<int, int>m;
    map<int, int>minmax;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(minmax.count(m[timestamp])){
            minmax[m[timestamp]]--;
            if(minmax[m[timestamp]] == 0){
                minmax.erase(m[timestamp]);
            }
        }
        minmax[price]++;
        m[timestamp] = price;
    }
    
    int current() {
        auto last = --m.end();
        return last->second;
    }
    
    int maximum() {
        auto l = --minmax.end();
        return l->first;
    }
    
    int minimum() {
        auto f = minmax.begin();
        return f->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */