class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> tmp, int used[], int n, int k, int now){
        if(tmp.size() == k){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = now; i <= n; i++){
            if(used[i] == 0){
                used[i] = 1;
                tmp.emplace_back(i);
                dfs(tmp, used, n, k, i + 1);
                used[i] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmp;
        int used[n + 5];
        memset(used, 0, sizeof(used));
        dfs(tmp, used, n, k, 1);
        return ans;
    }
};