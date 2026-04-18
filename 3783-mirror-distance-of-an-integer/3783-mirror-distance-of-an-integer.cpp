class Solution {
public:
    int mirrorDistance(int n) {
        int _n = n, rev_n = 0;
        while(n) {
            rev_n *= 10;
            rev_n += n % 10;
            n /= 10;
        }
        return abs(_n - rev_n);
    }
};