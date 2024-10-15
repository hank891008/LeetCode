class Solution {
public:
    long long minimumSteps(string st) {
        long long ans = 0;
        int cnt = 0;
        for(auto s: st){
            if(s == '0'){
                ans += cnt;
            }
            else{
                cnt++;
            }
        }
        return ans;
    }
};