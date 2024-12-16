class Solution {
public:
    bool isFascinating(int n) {
        string st = to_string(n) + to_string(2 * n) + to_string(3 * n);
        unordered_set<int> s;
        for(int i = 1; i <= 9; i++){
            s.insert(i);
        }
        for(int i = 0; i < st.size(); i++){
            if(!s.count(st[i] - '0')){
                return false;
            }
            s.erase(st[i] - '0');
        }
        return true;;
    }
};