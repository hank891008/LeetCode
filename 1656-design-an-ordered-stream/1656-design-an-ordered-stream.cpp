class OrderedStream {
public:
    vector<string> v;
    int id = 1;
    OrderedStream(int n) {
        v.resize(n + 5);
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        vector<string> ans;
        while(v[id] != ""){
            ans.emplace_back(v[id++]);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */