class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last = days.back();
        vector<int> dp(last + 1, 0);
        int idx = 0;

        for(int i = 1; i <= last; i++){
            if(i < days[idx]){
                dp[i] = dp[i - 1];
            }
            else{
                idx++;
                dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[last];
    }
};