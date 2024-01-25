class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int MAXN = 2e4 + 5;
        vector<int> v(MAXN);
        int minn = INT_MAX, maxx = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            v[nums[i]]++;
            minn = min(minn, nums[i]);
            maxx = max(maxx, nums[i]);
        }
        v[2] = 2 * v[2];
        for(int i = max(3, minn); i <= maxx; i++){
            v[i] = i * v[i] + max(v[i - 2], v[i - 3]);
        }
        return max(v[maxx], v[maxx - 1]);
    }
};