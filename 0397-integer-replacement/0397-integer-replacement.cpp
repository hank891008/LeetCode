class Solution {
public:
    unordered_map<long long, int>m;
    int dp(long long n){
        if(n == 1){
            return 0;
        }
        if(m.count(n)){
            return m[n];
        }
        if(n % 2 == 0){
            return m[n] = 1 + dp(n / 2);
        }
        else{
            return m[n] = 1 + min(dp((long long)n + 1), dp((long long)n - 1));
        }
        
    }
    int integerReplacement(int n) {
        return dp(n);
    }
};