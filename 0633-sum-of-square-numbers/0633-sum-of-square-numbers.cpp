class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = sqrt(c);
        while(b >= 0){
            int a_sq = c - b * b;
            printf("%d %d %d\n", a_sq, b * b, c);
            if(a_sq == ((int)sqrt(a_sq) * (int)sqrt(a_sq))){
                return true;
            }
            b--;
        }
        return false;
    }
};