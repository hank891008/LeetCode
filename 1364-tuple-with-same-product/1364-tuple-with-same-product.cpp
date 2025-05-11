class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                mp[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for(auto [x, y]: mp){
            ans += 8 * y * (y - 1) / 2;
        }
        return ans;
    }
};