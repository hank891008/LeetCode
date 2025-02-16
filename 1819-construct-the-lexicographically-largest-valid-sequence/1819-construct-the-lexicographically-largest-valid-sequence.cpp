class Solution {
public:
    bool dfs(int idx, vector<int>& ans, vector<bool>& used){
        if(idx == ans.size()){
            return true;
        }
        if(ans[idx] != 0){
            return dfs(idx + 1, ans, used);
        }
        for(int i = used.size() - 1; i >= 1; i--){
            if(used[i] == false){
                used[i] = true;
                ans[idx] = i;
                if(i == 1){
                    if(dfs(idx + 1, ans, used)){
                        return true;
                    }
                }
                else if(idx + i < ans.size() && ans[idx + i] == 0){
                    ans[idx + i] = i;
                    if(dfs(idx + 1, ans, used)){
                        return true;
                    }
                    ans[idx + i] = 0; 
                }
                used[i] = false;
                ans[idx] = 0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        dfs(0, ans, used);
        return ans;
    }
};