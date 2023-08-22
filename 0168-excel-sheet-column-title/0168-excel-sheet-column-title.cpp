class Solution {
public:
    string solve(int n){
        if(n == 0){
            return "";
        }
        char now = 'A' - 1 + n % 26;
        if(n % 26 == 0){
            now = 'Z';
        }
        return solve((n - 1) / 26) + now;
    }
    string convertToTitle(int columnNumber) {
        return solve(columnNumber);
    }
};