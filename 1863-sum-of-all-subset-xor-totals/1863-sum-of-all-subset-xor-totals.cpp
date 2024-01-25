class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < (1 << n); i++){
            int xor_sum = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    xor_sum ^= nums[j];
                }
            }
            ans += xor_sum;
        }
        return ans;
    }
};