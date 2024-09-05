class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int acc = accumulate(rolls.begin(), rolls.end(), 0);
        int remain = mean * (rolls.size() + n) - acc;
        if(remain > 6 * n || remain < n){
            return {};
        }
        vector<int> ans(n, remain / n);
        remain %= n;
        for(int i = 0; i < n; i++){
            if(remain == 0){
                break;
            }
            else if(remain + ans[i] > 6){
                remain -= (6 - ans[i]);
                ans[i] = 6;
            }
            else{
                ans[i] += remain;
                remain = 0;
            }
        }
        return ans;
    }
};