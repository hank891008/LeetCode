class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> table = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        return table[3][num / 1000] + table[2][num / 100 % 10] + table[1][num / 10 % 10] + table[0][num % 10];
    }
};