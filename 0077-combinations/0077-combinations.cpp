class Solution {
public:
    vector<int>tmp;
    vector<vector<int>> ans;
    void dfs(int n, int k, int now){
        if(tmp.size() == k){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = now; i <= n; i++){
            tmp.emplace_back(i);
            dfs(n, k, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};