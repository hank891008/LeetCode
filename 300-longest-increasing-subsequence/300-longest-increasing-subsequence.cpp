class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>s;
        for(int i = 0; i < nums.size(); i++){
            if(s.empty() or s.back() < nums[i]){
                s.emplace_back(nums[i]);
            }
            else{
                *lower_bound(s.begin(), s.end(), nums[i]) = nums[i];
            }
        }
        return s.size();
    }
};