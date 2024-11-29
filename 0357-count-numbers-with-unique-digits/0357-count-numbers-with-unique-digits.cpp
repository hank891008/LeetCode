class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        int ans = 10;
        int now = 9, base = 9;
        for(int i = 2; i <= n; i++){
            ans += now * base;
            now = now * base--;
        }
        return ans;
    }
};