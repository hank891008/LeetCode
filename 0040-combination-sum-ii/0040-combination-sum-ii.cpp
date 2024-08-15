class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& v, vector<int> tmp, int target, int idx){
        if(target == 0){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i < v.size(); i++){
            if((i == idx || v[i] != v[i - 1]) && target - v[i] >= 0){
                tmp.emplace_back(v[i]);
                dfs(v, tmp, target - v[i], i + 1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());
        vector<int>tmp;
        dfs(candidates, tmp, target, 0);
        return ans;
    }
};