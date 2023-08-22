class Solution {
public:
    int titleToNumber(string columnTitle) {
        int tot = 0;
        long long base = 1;
        for(int i = columnTitle.size() - 1; i >= 0; i--){
            tot += (columnTitle[i] - 'A' + 1) * base;
            base *= 26;
        }
        return tot;
    }
};