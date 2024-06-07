class Solution {
public:
    vector<int> init;
    Solution(vector<int>& nums) {
        init = nums;
    }
    
    vector<int> reset() {
        return init;
    }
    
    vector<int> shuffle() {
        vector<int> ans(init.begin(), init.end());
        for(int i = 0; i < ans.size(); i++){
            swap(ans[i], ans[rand() % ans.size()]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */