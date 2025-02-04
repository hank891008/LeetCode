class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int prev = 0, now = 0, ans = 0;
        for(auto num: nums){
            if(num > prev){
                now += num;
            }
            else{
                now = num;
            }
            prev = num;
            ans = max(ans, now);
        }
        return ans;
    }
};