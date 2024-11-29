class Solution {
public:
    int ans;
    int used[20];
    void dfs(vector<int>& now, int start_idx, int n){
        if(now.size() == n){
            ans++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(!used[i] && (i % start_idx == 0 || start_idx % i == 0)){
                used[i] = true;
                now.emplace_back(i);
                dfs(now, start_idx + 1, n);
                now.pop_back();
                used[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> now;
        for(int i = 1; i <= n; i++){
            used[i] = true;    
            now.emplace_back(i);
            dfs(now, 2, n);
            now.pop_back();
            used[i] = false;
        }
        return ans;
    }
};