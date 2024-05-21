class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> now;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (1 << nums.size()); i++){
            now.clear();
            for(int j = 0; j < nums.size(); j++){
                if((i >> j) & 1){
                    now.emplace_back(nums[j]);
                }
            }
            if(!s.count(now)){
                s.insert(now);
                ans.emplace_back(now);
            }    
        }
        return ans;
    }
};