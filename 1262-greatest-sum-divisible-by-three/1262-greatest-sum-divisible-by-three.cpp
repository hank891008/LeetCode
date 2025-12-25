class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> ans = {0, INT_MIN, INT_MIN};
        for(auto &num: nums) {
            vector<int> tmp = ans;
            tmp[(0 + num % 3) % 3] = max(tmp[(0 + num % 3) % 3], ans[0] + num);
            tmp[(1 + num % 3) % 3] = max(tmp[(1 + num % 3) % 3], ans[1] + num);
            tmp[(2 + num % 3) % 3] = max(tmp[(2 + num % 3) % 3], ans[2] + num);
            ans = move(tmp);
        }
        return ans[0];
    }
};