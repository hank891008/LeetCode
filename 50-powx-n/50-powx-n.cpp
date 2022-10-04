class Solution {
public:
    double power(double x, long long n){
        double ret = 1;
        while(n > 0){
            if(n & 1){
                ret *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ret;
        
    }
    double myPow(double x, int n) {
        long long nn = n;
        bool pos = 1 ? n >= 0: 0;
        if(!pos){
            nn = -nn;
        }
        double ans = power(x, nn);
        if(pos){
            return ans;
        }
        else{
            return 1 / ans;
        }
    }
};