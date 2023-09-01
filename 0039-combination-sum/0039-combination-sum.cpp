class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>>s;
    void dfs(vector<int>& v, vector<int> tmp, int target){
        if(target == 0){
            sort(tmp.begin(), tmp.end());
            if(s.count(tmp)){
                return;
            }
            s.insert(tmp);
            ans.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < v.size(); i++){
            if(target - v[i] >= 0){
                tmp.emplace_back(v[i]);
                dfs(v, tmp, target - v[i]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());
        vector<int>tmp;
        dfs(candidates, tmp, target);
        return ans;
    }
};