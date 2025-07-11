class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto a: arr){
            mp[a]++;
        }
        int ans = -1;
        for(auto [x, y]: mp){
            if(x == y && x > ans){
                ans = x;
            }
        }
        return ans;
    }
};