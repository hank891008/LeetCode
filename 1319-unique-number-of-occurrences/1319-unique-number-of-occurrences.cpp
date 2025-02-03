class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto& a: arr){
            m[a]++;
        }
        unordered_set<int> s;
        for(auto [_, v]: m){
            if(s.count(v)){
                return false;
            }
            s.insert(v);
        }
        return true;
    }
};