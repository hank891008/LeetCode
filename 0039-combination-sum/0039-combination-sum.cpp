class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& v, int idx, vector<int> tmp, int target){
        if(target == 0){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i < v.size(); i++){
            if(target - v[i] >= 0){
                tmp.emplace_back(v[i]);
                dfs(v, i, tmp, target - v[i]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());
        vector<int>tmp;
        dfs(candidates, 0, tmp, target);
        return ans;
    }
};