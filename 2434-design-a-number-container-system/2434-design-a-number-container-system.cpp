class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    unordered_map<int, int> table;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        table[index] = number;
        mp[number].emplace(index);
    }
    
    int find(int number) {
        while(!mp[number].empty()){
            int idx = mp[number].top();
            if(table[idx] == number){
                return idx;
            }
            mp[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */