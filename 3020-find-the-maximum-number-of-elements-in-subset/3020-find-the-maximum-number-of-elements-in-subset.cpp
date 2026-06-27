class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(auto num: nums) {
            mp[num]++;
        }
        int ans = mp[1] % 2 == 0 ? mp[1] - 1 : mp[1];
        mp.erase(1);
        for(auto [k, v]: mp) {
            int t = 0;
            long long int x = k;
            while(mp.count(x) && mp[x] > 1) {
                x = x * x;
                t += 2;
            }
            t += mp.count(x) ? 1 : -1;
            ans = max(ans, t);
        }
        return ans;
    }
};