class Solution {
public:
    int scoreOfString(string s) {
        int tot = 0, pre = s[0];
        for(auto ss: s){
            tot += abs(ss - pre);
            pre = ss;
        }
        return tot;
    }
};