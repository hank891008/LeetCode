class Solution {
public:
    vector<string>ans;
    void dfs(string now, int l, int r, int n){
        if(l == r && l == n){
            int tot = 0;
            for(int i = 0; i < now.size(); i++){
                if(now[i] == '('){
                    tot++;
                }
                else{
                    tot--;
                }
                if(tot < 0){
                    return;
                }
            }
            ans.emplace_back(now);
            return;
        }
        if(l > n || r > n){
            return;
        }
        dfs(now + "(", l + 1, r, n);
        dfs(now + ")", l, r + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return ans;
    }
};