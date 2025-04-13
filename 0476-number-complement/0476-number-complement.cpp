class Solution {
public:
    int findComplement(int num) {
        for(int i = 0, j = num; i < 31 && j != 0; i++, j >>= 1){
            num ^= (1 << i);
        }
        return num;
    }
};