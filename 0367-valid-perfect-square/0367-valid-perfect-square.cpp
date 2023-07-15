class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        long long l = 1, r = num / 2;
        while(l <= r){
            long long mid = l - (l - r) / 2;
            if(mid * mid > num){
                r = mid - 1;
            }
            else if(mid * mid == num){
                return true;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};