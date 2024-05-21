class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> now;
        for(int i = 0; i < (1 << nums.size()); i++){
            now.clear();
            for(int j = 0; j < nums.size(); j++){
                if((i >> j) & 1){
                    now.emplace_back(nums[j]);
                }
            }
            ans.emplace_back(now);
        }
        return ans;
    }
};