class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0, diag2 = 0;
        for(auto d: dimensions){
            if(d[0] * d[0] + d[1] * d[1] > diag2){
                diag2 = d[0] * d[0] + d[1] * d[1];
                area = d[0] * d[1];
            }
            else if(d[0] * d[0] + d[1] * d[1] == diag2){
                area = max(area, d[0] * d[1]);
            }
        }
        return area;
    }
};