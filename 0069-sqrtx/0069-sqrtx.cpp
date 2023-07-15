class Solution {
public:
    int mySqrt(int x) {
        if(x == 1){
            return 1;
        }
        long long l = 0, r = x;
        while(l < r){
            long long mid = (l + r) / 2;
            if(mid * mid > x){
                r = mid;
            }
            else if(mid * mid == x){
                return mid;
            }
            else{
                l = mid;
            }
            if(l * l < x && (l + 1) * (l + 1) > x){
                return l;
            }
        }
        return l;
    }
};