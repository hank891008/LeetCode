class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int MAXN = 2e4 + 5;
        vector<int> v(MAXN);
        for(int i = 0; i < nums.size(); i++){
            v[nums[i]]++;
        }
        v[2] = 2 * v[2];
        for(int i = 3; i < MAXN; i++){
            v[i] = i * v[i] + max(v[i - 2], v[i - 3]);
        }
        return max(v[MAXN - 1], v[MAXN - 2]);
    }
};