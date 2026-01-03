class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num: nums) {
            if(++mp[num] > 1) {
                return num;
            }
        }
        return -1;
    }
};