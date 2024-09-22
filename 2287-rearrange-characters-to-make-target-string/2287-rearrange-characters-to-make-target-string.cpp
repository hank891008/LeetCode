class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> k, v;
        for(auto st: s){
            k[st]++;
        }
        for(auto st: target){
            v[st]++;
        }
        int ans = INT_MAX;
        for(auto [x, y]: v){
            if(!k.count(x)){
                return 0;
            }
            ans = min(ans, k[x] / y);
        }
        return ans;
    }
};