class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, base = 1;
        while (n) {
            if (n % 10 != 0) {
                int d = n % 10;
                sum += d;
                x += d * base;
                base *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};