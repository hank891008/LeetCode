class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        pair<int, int> v1 = {p[0][0] - p[1][0], p[0][1] - p[1][1]};
        pair<int, int> v2 = {p[0][0] - p[2][0], p[0][1] - p[2][1] };
        return v1.first * v2.second - v1.second * v2.first != 0;
    }
};