class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }
        int minn = INT_MAX;
        int idx = 0;
        for(int i = 0; i < n - 1; i++){
            int left = prefix[i] / (i + 1);
            int right = (prefix[n - 1] - prefix[i]) / (n - (i + 1));
            if(abs(left - right) < minn){
                idx = i;
                minn = abs(left - right);
            }
        }
        if(prefix[n - 1] / n < minn){
            idx = n - 1;
        }
        return idx;
    }
};