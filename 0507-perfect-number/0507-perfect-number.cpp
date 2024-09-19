class Solution {
public:
    bool checkPerfectNumber(int num) {
        int tot = 0;
        for(int i = 1; i <= num / 2; i++){
            if(num % i == 0){
                tot += i;
            }
        }
        return tot == num;
    }
};