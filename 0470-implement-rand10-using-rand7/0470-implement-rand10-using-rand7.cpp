// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int tot = 0;
        for(int i = 0; i < 10; i++){
            tot += rand7();
        }
        return tot % 10 + 1;
    }
};