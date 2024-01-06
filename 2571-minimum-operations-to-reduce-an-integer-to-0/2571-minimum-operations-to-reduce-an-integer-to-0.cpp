class Solution {
public:
    int minOperations(int n) {
        int cnt = 0;
        int ans = 0;
        while(n != 0){
            bool one = (n % 2);
            n >>= 1;
            if(one){
                cnt++;
            }
            else{
                if(cnt == 1){
                    ans++;
                    cnt = 0;
                }
                else if(cnt > 1){
                    ans += 1;
                    cnt = 1;
                }
            }
        }
        if(cnt == 1){
            ans++;
        }
        else if(cnt > 1){
            ans += 2;
        }
        return ans;
    }
};