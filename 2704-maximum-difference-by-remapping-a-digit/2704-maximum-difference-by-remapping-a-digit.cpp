class Solution {
public:
    int minMaxDifference(int num) {
        string big = to_string(num), small = to_string(num);
        char b = '$', s = '$';
        for(int i = 0; i < big.size(); i++) {
            if(b == '$' && big[i] != '9') {
                b = big[i];
                big[i] = '9';
            } else if(b == big[i]) {
                big[i] = '9';
            }
            if(s == '$' && small[i] != '0') {
                s = small[i];
                small[i] = '0';
            } else if(s == small[i]) {
                small[i] = '0';
            }
        }
        return stoi(big) - stoi(small);
    }
};