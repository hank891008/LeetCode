class Solution {
public:
    long long coloredCells(int n) {
        // 1 -> 5 -> 13 -> 25 ->  41 -> 61
        //   4    8     12    16    20
        return (long long)2 * n * n - 2 * n + 1;
    }
};