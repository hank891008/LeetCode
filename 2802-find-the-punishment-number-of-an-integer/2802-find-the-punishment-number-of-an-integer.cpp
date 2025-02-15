class Solution {
public:
    bool check(int num, int tar){
        if(tar < 0 || num < tar){
            return false;
        }
        if(num == tar){
            return true;
        }
        return check(num / 10, tar - num % 10) || check(num / 100, tar - num % 100) || check(num / 1000, tar - num % 1000);
    }
    
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(check(i * i, i)){
                ans += i * i;
            }
        }
        return ans;
    }
};