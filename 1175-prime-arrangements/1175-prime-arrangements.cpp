class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numPrimeArrangements(int n) {
        long long f[105] = {1};
        for(int i = 1; i <= 100; i++){
            f[i] = (f[i - 1] * i) % MOD;
        }
        
        unordered_set<int> s = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        int cnt_p = 0;
        for(int i = 2; i <= n; i++){
            if(s.count(i)){
                cnt_p++;
            }
        }
        return (f[cnt_p] * f[n - cnt_p]) % MOD;
        
    }
};