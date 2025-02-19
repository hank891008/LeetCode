class Solution {
public:
    int cnt = 0;
    string ans;
    void solve(int n, int k, string now){
        if(cnt >= k){
            return;
        }
        if(now.size() == n){
            cnt++;
            if(cnt == k){
                ans = now;
            }
            return;
        }
        for(int i = 0; i < 3; i++){
            if(now.size() > 0 && now.back() == ('a' + i)){
                continue;
            }
            solve(n, k, now + char('a' + i));
        }
    }
    string getHappyString(int n, int k) {
        solve(n, k, "");
        if(cnt >= k){
            return ans;
        }
        return "";
    }
};