class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        /*
        a <= b <= c <= d <= e
        if sum of d as max
        -> (d * d) * d + a * 2^2 + b * 2^1 + c * 2^0 + c * 2^0
        
        let s = a * 2^2 + b * 2^1 + c * 2^0
        -> d * d * (d + s)
        if choose e as max
        -> new_s = (a * 2^3 + b * 2^2 + c * 2^1 + d * 2^0) = 2 * s + d;

        */
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int ans = 0, prev = 0;
        for(long long num: nums){
            int now = (num * num % MOD * (num + prev) % MOD) % MOD;
            ans = (ans + now) % MOD;
            prev = (2 * prev + num) % MOD;
        }
        return ans;
    }
};