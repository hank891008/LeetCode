class Solution {
public:
    long long comb2(int x){
        return 1LL * (x) * (x - 1) / 2;
    }
    long long distributeCandies(int n, int m) {
        if(m * 3 < n){
            return 0;
        }
        else if(n >= 0 && n < m + 1){
            return comb2(n + 2);
        }
        else if(n < 2 * (m + 1)){
            return comb2(n + 2) - 3 * comb2(n + 2 - (m + 1));
        }
        else if(n < 3 * (m + 1)){
            return comb2(n + 2) - 3 * comb2(n + 2 - (m + 1)) + 3 * comb2(n + 2 - 2 * (m + 1));
        }
        return comb2(n + 2) - 3 * comb2(n + 2 - (m + 1)) + 3 * comb2(n + 2 - 2 * (m + 1)) -  3 * comb2(n + 2 - 3 * (m + 1));
    }
};