class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return vector<int>(1);
        }
        int prefix[1005] = {nums[0]};
        for(int i = 1; i < n; i++){
            prefix[i] += prefix[i - 1] + nums[i];
        }
        
        vector<int> ans;
        ans.emplace_back(prefix[n - 1] - prefix[0]);
        for(int i = 1; i < n - 1; i++){
            ans.emplace_back(abs(prefix[i - 1] - (prefix[n - 1] - prefix[i])));
        }
        ans.emplace_back(prefix[n - 2]);
        return ans;
    }
};