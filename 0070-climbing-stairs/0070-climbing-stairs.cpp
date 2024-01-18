class Solution {
public:
    int climbStairs(int n) {
        int ans[50] = {0, 1, 2};
        for(int i = 3; i <= n; i++){
            ans[i] = (ans[i - 1] + ans[i - 2]);
        }
        return ans[n];
    }
};