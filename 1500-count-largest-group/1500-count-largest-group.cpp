class Solution {
public:
    int to_digit(int x){
        int tot = 0;
        while(x != 0){
            tot += x % 10;
            x /= 10;
        }
        return tot;
    }
    int countLargestGroup(int n) {
        int ans[40] = {0};
        int maxx = 0, cnt = 1;
        for(int i = 1; i <= n; i++){
            int digit = to_digit(i);
            if(++ans[digit] > maxx){
                maxx = ans[digit];
                cnt = 1;
            }
            else if(ans[digit] == maxx){
                cnt++;
            }
        }
        return cnt;
    }
};