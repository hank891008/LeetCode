class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> s({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});
        int ans = 0;
        for(int i = left; i <= right; i++){
            int bits = __builtin_popcount(i);
            ans += s.count(bits);
        }
        return ans;
    }
};