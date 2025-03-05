class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, ans = 0;
        for(auto now: s){
            if(now == 'E'){
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};