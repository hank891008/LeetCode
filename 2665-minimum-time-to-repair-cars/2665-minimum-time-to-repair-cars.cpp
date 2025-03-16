class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        while(l < r){
            long long m = l + (r - l) / 2;
            long long cnt = 0;
            for(auto rank: ranks){
                // rank * n * n = m -> sqrt(m / rank) = n;
                cnt += sqrt(m / rank);
            }
            if(cnt >= cars){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};