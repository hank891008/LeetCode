class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto a: arr){
            m[a]++;
        }
        if(m[0] >= 2){
            return true;
        }
        for(auto [k, v]: m){
            if(m.count(2 * k) && k != 0){
                return true;
            }
        }
        return false;
    }
};