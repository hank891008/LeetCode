class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto& d: dominoes){
            ans += (++mp[min(d[0], d[1]) * 10 + max(d[0], d[1])] - 1);
            
        }
        return ans;
    }
};