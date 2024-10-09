class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            cnt = max(0, cnt + (s[i] == '[') - (s[i] == ']'));
        }
        return (cnt + 1) / 2;
    }
};