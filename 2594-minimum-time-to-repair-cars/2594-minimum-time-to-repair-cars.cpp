class Solution {
public:
    using LL = long long;
    bool check(vector<int>& ranks, LL min, int cars){
        LL cnt = 0;
        for(auto rank: ranks){
            cnt += sqrt(min / rank);
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        LL l = 0, r = (LL)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        while(l < r){
            LL m = l + (r - l) / 2;
            if(check(ranks, m, cars)){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};