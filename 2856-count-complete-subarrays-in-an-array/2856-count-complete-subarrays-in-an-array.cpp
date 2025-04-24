class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(auto num: nums){
            s.insert(num);
        }
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        while(i < nums.size()){
            while(j < nums.size() && mp.size() < s.size()){
                mp[nums[j]]++;
                j++;
            }
            if(mp.size() == s.size()){
                ans += (nums.size() - j + 1);
            }
            mp[nums[i]]--;
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
            i++;
        }
        return ans;
    }
};