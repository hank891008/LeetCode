class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> pow2_table;

    void precompute_pow2(int n) {
        pow2_table.resize(n + 2);
        pow2_table[0] = 1;
        for (int i = 1; i <= n + 1; i++) {
            pow2_table[i] = (2LL * pow2_table[i - 1]) % MOD;
        }
    }

    int pow2(int x) {
        return pow2_table[x];
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        precompute_pow2(n);

        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        long long ans = 0;
        vector<pair<int, int>> keys(mp.begin(), mp.end());
        vector<int> prefix_sum(keys.size() + 1, 0);

        for (int i = 0; i < keys.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + keys[i].second;
        }

        for (int i = 0; i < keys.size(); i++) {
            int x = keys[i].first;
            int y = keys[i].second;
            int diff = target - x;
            if (diff < x) {
                break;
            }
            auto it = upper_bound(keys.begin(), keys.end(), make_pair(diff, INT_MAX));
            int j = distance(keys.begin(), it) - 1;
            int cnt = prefix_sum[j + 1] - prefix_sum[i + 1];

            int a = (pow2(y) - 1 + MOD) % MOD;
            int b = pow2(cnt);
            long long temp = (1LL * a * b) % MOD;
            ans = (ans + temp) % MOD;
        }

        return ans;
    }
};