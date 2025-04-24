class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(auto num: nums){
            s.insert(num);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            map<int, int> mp;
            for(int j = i; j < nums.size(); j++){
                mp[nums[j]]++;
                if(mp.size() == s.size()){
                    ans += nums.size() - j;
                    break;
                }
            }
        }
        return ans;
    }
};