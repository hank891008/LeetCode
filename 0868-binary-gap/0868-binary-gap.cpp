class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1, now = 0;
        while(n) {
            if(n & 1) {
                if(prev != -1) {
                    ans = max(ans, now - prev);
                    prev = now;
                }
                prev = now;
            }
            now++;
            n >>= 1;
        }
        return ans;
    }
};