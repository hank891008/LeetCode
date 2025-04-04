class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long first = 0, sum = 0, ans = 0;
        for(auto num: nums){
            ans = max(ans, sum * num);
            sum = max(sum, first - num);
            first = max(first, static_cast<long long>(num));
        }
        return ans;
    }
};