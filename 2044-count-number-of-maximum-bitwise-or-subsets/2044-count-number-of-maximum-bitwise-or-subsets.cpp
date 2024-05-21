class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0;
        for(auto num: nums){
            maxx |= num;
        }
        int ans = 0;
        for(int i = 0; i < (1 << n); i++){
            int now = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    now |= nums[j];
                }
            }
            if(now == maxx){
                ans++;
            }
        }
        return ans;
    }
};