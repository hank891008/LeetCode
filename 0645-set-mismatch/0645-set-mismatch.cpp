class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(i + 1);
        }
        int ans;
        for(int i = 0; i < nums.size(); i++){
            if(!s.count(nums[i])){
                ans = nums[i];
            }
            s.erase(nums[i]);
        }
        return {ans, *s.begin()};
    }
};