class Solution {
public:
    bool isSameAfterReversals(int num) {
        int tmp = num;
        while(tmp >= 10 && tmp % 10 == 0){
            tmp /= 10;
        }
        return tmp == num;
    }
};