class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> mp;
        for(int i = 0; i + k <= s.size(); i++) {
            mp.insert(s.substr(i, k));
            if(mp.size() == (1 << k)) {
                break;
            }
        }
        return mp.size() == (1 << k);
    }
};