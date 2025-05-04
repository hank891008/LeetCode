class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto& d: dominoes){
            if(d[0] > d[1]){
                swap(d[0], d[1]);
            }
            ans += (++mp[d[0] * 10 + d[1]] - 1);
            
        }
        return ans;
    }
};