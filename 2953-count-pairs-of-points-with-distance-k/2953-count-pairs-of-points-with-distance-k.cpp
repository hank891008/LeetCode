class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans = 0;
        int base = 1e7;
        unordered_map<long long, int> mp;
        for(auto c: coordinates){
            long long x = c[0], y = c[1];
            for(int dx = 0; dx <= k; dx++){
                ans += mp[{(x ^ dx) * base + y ^ (k - dx)}];
            }
            mp[{x * base + y}]++;
        }
        return ans;
    }
};