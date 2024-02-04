class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int x = points[0][0], y = points[0][1];
        int ans = 0;
        for(int i = 1; i < n; i++){
            int next_x = points[i][0], next_y = points[i][1];
            ans += max(abs(next_x - x), abs(next_y - y));
            x = next_x, y = next_y;
        }
        return ans;
    }
};