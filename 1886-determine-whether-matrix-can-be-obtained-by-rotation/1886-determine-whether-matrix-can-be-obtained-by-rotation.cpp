class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>>ret;
        for(int i = 0; i < mat.size(); i++){
            vector<int>v((int)mat.size(), 0);
            ret.push_back(v);
        }
        for(int k = 0; k < 4; k++){
            for(int i = mat.size() - 1; i >= 0; i--){
                for(int j = 0; j < mat[i].size(); j++){
                    ret[j][mat.size() - 1 - i] = mat[i][j];
                }
            }
            mat = ret;
            int flag = 1;
            for(int i = 0; i < mat.size(); i++){
                if(!flag){
                    break;
                }
                for(int j = 0; j < mat[0].size(); j++){
                    if(mat[i][j] != target[i][j]){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};