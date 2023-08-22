class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int prefix[n];
        memset(prefix, 0, sizeof(prefix));
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<int>ans;
        ans.emplace_back(prefix[n - 1] - prefix[0] - (n - 1) * prefix[0]);
        for(int i = 1; i < n; i++){
            int greater = (prefix[n - 1] - prefix[i]) - (n - 1 - i) * nums[i];
            int lesser = nums[i] * i - prefix[i - 1];
            ans.emplace_back(lesser + greater);
        }
        return ans;
    }
};