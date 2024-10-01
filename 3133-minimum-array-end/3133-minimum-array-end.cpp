class Solution {
public:
    long long minEnd(int n, int x) {
        long long bit[64];
        for(int i = 0; i < 64; i++){
            bit[i] = x & 1;
            x >>= 1;
        }
        
        n -= 1;
        int idx = 0;
        while(n > 0){
            while(bit[idx] == 1){
                idx++;
            }
            bit[idx++] = n & 1;
            n >>= 1;
        }

        long long ans = 0;
        for(int i = 0; i < 64; i++){
            ans += (bit[i] << i);
        }
        return ans;
    }
};