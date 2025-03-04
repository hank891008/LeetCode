class Solution {
public:
    bool checkPowersOfThree(int n) {
        int max_pow = 1;
        while(max_pow < 1e7){
            max_pow *= 3;
        }
        while(max_pow > 0 && n > 0){
            if(n >= max_pow){
                n -= max_pow;
            }
            max_pow /= 3;
        }
        return n == 0;
    }
};