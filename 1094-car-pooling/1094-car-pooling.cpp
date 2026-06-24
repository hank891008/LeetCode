class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        for(auto trip: trips) {
            int p = trip[0], from = trip[1], to = trip[2];
            mp[from] += p;
            mp[to] -= p;
        }
        int curr = 0;
        for(auto& [k, v]: mp) {
            curr += v;
            if(curr > capacity) {
                return false;
            }
        }
        return true;
    }
};