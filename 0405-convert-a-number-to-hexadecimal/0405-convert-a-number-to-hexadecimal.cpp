class Solution {
public:
    string toHex(int num) {
        string hexmap = "0123456789abcdef";
        string hex = "0";
        int cnt = 0;
        int first_idx = 8;
        while(cnt++ < 8){
            hex += hexmap[((num >> 28) & 0xf)];
            if(hex.back() != '0' && first_idx == 8){
                first_idx = cnt;
            }
            num <<= 4;
        }
        return hex.substr(first_idx);
    }
};