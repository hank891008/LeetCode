class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>>ans;
        vector<int>tmp;
        if(m * n == o.size()){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    tmp.emplace_back(o[i * n + j]);
                }
                ans.emplace_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};