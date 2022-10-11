class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>ret;
        for(int i = 0; i < matrix.size(); i++){
            vector<int>v((int)matrix.size(), 0);
            ret.push_back(v);
        }
        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = 0; j < matrix[i].size(); j++){
                ret[j][matrix.size() - 1 - i] = matrix[i][j];
            }
        }
        matrix = ret;
    }
};