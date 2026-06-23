class Solution {
public:
    bool scoreBalance(string s) {
        int total = 0;
        unordered_set<int> Set;
        for(auto ch: s) {
            total += (ch - 'a' + 1);
            Set.insert(total);
        }
        return total % 2 == 0 ? Set.count(total / 2) : false;
    }
};