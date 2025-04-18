class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' + (i % 2)){
                ans1++;
            }
            if(s[i] == '1' - (i % 2)){
                ans2++;
            }
        }
        return min(ans1, ans2);
    }
};