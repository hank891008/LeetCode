class Solution {
public:
    bool checkZeroOnes(string s) {
        int max_s[2] = {(s[0] == '0'), (s[0] == '1')};
        int cur_s[2] = {(s[0] == '0'), (s[0] == '1')};
        for(int i = 1; i < s.size(); i++) {
            int idx = s[i] - '0';
            if(s[i] == s[i - 1]) {
                cur_s[idx]++;
            } else {
                max_s[!idx] = max(max_s[!idx], cur_s[!idx]);
                cur_s[!idx] = 0;
                cur_s[idx] = 1;
            }
        }
        return max(max_s[0], cur_s[0]) < max(max_s[1], cur_s[1]);
    }
};