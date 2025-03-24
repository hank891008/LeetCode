class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }
        int ans = 0;
        for(auto [x, y]: mp){
            if(mp.count(k - x)){
                ans += min(y, mp[k - x]);
            }
        }
        return ans / 2;
    }
};