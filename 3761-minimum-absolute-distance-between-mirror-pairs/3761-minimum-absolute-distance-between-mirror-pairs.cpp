class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                ans = min(ans, abs(i - mp[nums[i]]));
            }
            mp[reverse(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};