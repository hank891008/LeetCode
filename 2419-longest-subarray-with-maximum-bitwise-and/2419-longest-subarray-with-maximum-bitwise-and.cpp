class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = *max_element(nums.begin(), nums.end());
        int curr = 0, maxx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != k){
                curr = 0;
                continue;
            }
            maxx = max(maxx, ++curr);
        }
        return maxx;
    }
};