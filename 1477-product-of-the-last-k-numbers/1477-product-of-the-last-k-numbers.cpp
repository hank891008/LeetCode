class ProductOfNumbers {
public:
    vector<int> v = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            v.clear();
            v.emplace_back(1);
        }
        else{
            v.emplace_back(num * v.back());
        }
    }
    
    int getProduct(int k) {
        if(v.size() <= k){
            return 0;
        }
        return v.back() / v[(int)v.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */