class Solution {
public:
    map<pair<int, int>, double>m;
    double dp(int a, int b){
        if(a > 5000){
            return 1;
        }
        if(m.count({a, b})){
            return m[{a, b}];
        }
        if(a <= 0 && b > 0){
            return 1;
        }
        else if(a <= 0 && b <= 0){
            return 0.5;
        }
        else if(a > 0 && b <= 0){
            return 0;
        }
        return m[{a, b}] = 0.25 * (dp(a - 100, b) + dp(a - 75, b - 25) + dp(a - 50, b - 50) + dp(a - 25, b - 75));
    }
    double soupServings(int n) {
        return dp(n, n);
    }
};