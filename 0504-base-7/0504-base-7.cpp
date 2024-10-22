class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        string ans;
        int flag = num < 0;
        if(flag){
            num *= -1;
        }
        while(num > 0){
            ans += to_string(num % 7);
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        return flag ? '-' + ans : ans;
    }
};