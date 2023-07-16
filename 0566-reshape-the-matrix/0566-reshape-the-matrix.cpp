class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r * c != mat.size() * mat[0].size()){
            return mat;
        }
        vector<vector<int>> v;
        vector<int>row;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                row.emplace_back(mat[i][j]);
                if(row.size() == c){
                    v.emplace_back(row);
                    row.clear();
                }
            }
        }
        return v;
    }
};