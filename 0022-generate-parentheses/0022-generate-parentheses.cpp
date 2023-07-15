class Solution {
public:
    vector<string>ans;
    void dfs(string now, int l, int r, int n){
        if(r > l || l > n || r > n){
            return;
        }
        if(l == r && l == n){
            ans.emplace_back(now);
            return;
        }
        dfs(now + "(", l + 1, r, n);
        dfs(now + ")", l, r + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        dfs("(", 1, 0, n);
        return ans;
    }
};