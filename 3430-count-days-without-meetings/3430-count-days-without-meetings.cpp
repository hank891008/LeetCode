class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0, last = 0;
        sort(meetings.begin(), meetings.end());
        for(auto& meeting: meetings){
            int s = meeting[0], e = meeting[1];
            if(s > last + 1) {
                ans += s - (last + 1);
            }
            last = max(last, e);
        }
        return ans + days - last;
    }
};