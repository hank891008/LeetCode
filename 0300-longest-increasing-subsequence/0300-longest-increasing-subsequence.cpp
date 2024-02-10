class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans = {-20000};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.emplace_back(nums[i]);
            }
            for(int j = ans.size() - 1; j >= 0; j--){
                if(ans[j] < nums[i]){
                    ans[j + 1] = min(ans[j + 1], nums[i]);
                }
            }
        }
        return ans.size() - 1;
    }
};