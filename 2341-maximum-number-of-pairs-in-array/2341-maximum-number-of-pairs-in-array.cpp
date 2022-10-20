class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int equal = 0, pair = 0;
        for(auto it: mp){
            equal += it.second % 2;
            pair += it.second / 2;
        }
        return {pair, equal};
    }
};