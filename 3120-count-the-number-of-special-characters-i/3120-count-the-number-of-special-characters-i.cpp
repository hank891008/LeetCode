class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_set<int> s;
        for(auto w: word) {
            s.insert(w);
        }
        for(int i = 0; i < 26; i++) {
            if(s.count('a' + i) && s.count('A' + i)) {
                ans++;
            }
        }
        return ans;
    }
};