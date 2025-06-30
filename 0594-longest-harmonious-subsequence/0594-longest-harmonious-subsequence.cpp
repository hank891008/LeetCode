class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto num: nums){
            mp[num]++;
        }
        for(auto& [num, cnt]: mp){
            if(mp.count(num - 1)){
                ans = max(ans, cnt + mp[num - 1]);
            }
        }
        return ans;
    }
};