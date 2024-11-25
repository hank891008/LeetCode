class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        long long tot = 0;
        int min_abs = INT_MAX;
        for(auto &i: matrix){
            for(auto &j: i){
                tot += abs(j);
                if(j < 0){
                    neg++;
                }
                min_abs = min(min_abs, abs(j));
            }
        }
        return tot - (neg & 1) * 2 * min_abs;
        
    }
};