class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto& num: nums){
            int cnt = 0;
            while(num > 0){
                cnt++;
                num /= 10;
            }
            ans += (cnt % 2 == 0);
        }
        return ans;
    }
};