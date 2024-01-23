class Solution {
public:
    vector<string>now;
    int used[30];
    int ans;
    int check(){
        bool alpha[30] = {0};
        int tot = 0;
        for(auto st: now){
            for(auto s: st){
                if(alpha[s - 'a'] == true){
                    return -1;
                }
                alpha[s - 'a'] = true;
                tot++;
            }
        }
        return tot;
    }
    void dfs(int idx, vector<string>& arr){
        for(int i = idx + 1; i < arr.size(); i++){
            if(!used[i]){
                now.emplace_back(arr[i]);
                int chk = check();
                if(chk != -1){
                    used[i] = true;
                    ans = max(ans, chk);
                    dfs(i, arr);
                }
                now.pop_back();
                used[i] = false;
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        dfs(-1, arr);
        return ans;
    }
};