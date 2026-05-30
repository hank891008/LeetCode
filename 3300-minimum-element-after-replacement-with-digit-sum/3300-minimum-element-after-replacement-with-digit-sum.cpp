class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 36;
        for(auto num: nums) {
            int curr = 0;
            while(num) {
                curr += num % 10;
                num /= 10;
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};