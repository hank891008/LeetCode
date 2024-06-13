class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++, a >>= 1, b >>= 1, c >>= 1){
            if(c & 1 == 1){
                if((a & 1) + (b & 1) == 0){
                    ans += 1;
                }
            }
            else{
                ans += (a & 1) + (b & 1);
            }
        }
        return ans;
    }
};