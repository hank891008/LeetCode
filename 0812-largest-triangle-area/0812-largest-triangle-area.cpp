class Solution {
public:
    double solve(vector<int> a, vector<int> b, vector<int> c){
        vector<int> A = {b[0] - a[0], b[1] - a[1]};
        vector<int> B = {c[0] - a[0], c[1] - a[1]};
        return 0.5 * abs(A[0] * B[1] - B[0] * A[1]);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    ans = max(ans, solve(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};