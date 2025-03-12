class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        }); 
        int ans = 0;
        int right = intervals[0][1];
        for(int i = 1; i < n; i++){
            int x = intervals[i][0], y = intervals[i][1];
            if(x < right){
                ans++;
                continue;
            }
            right = y;
        }
        return ans;
    }
};