class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(i + 1);
        }
        for(int i = 0; i < nums.size(); i++){
            s.erase(nums[i]);
        }
        vector<int> ans;
        for(auto it: s){
            ans.emplace_back(it);
        }
        return ans;
    }
};