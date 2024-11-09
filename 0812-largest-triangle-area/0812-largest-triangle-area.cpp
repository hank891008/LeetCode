class Solution {
public:
    double cal(vector<int> a, vector<int> b){
        return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    }
    double solve(vector<int> a, vector<int> b, vector<int> c){
        double A = cal(a, b);
        double B = cal(a, c);
        double C = cal(b, c);
        double S = (A + B + C) / 2;
        return sqrt(S * (S - A) * (S - B) * (S - C));
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