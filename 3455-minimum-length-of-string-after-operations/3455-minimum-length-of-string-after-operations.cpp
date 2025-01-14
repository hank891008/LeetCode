class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        int ans = 0;
        for(auto [x, y]: m){
            ans += 1 * (y & 1) + 2 * !(y & 1);
        }
        return ans;
    }
};