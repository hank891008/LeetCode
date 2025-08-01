class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(1, {1});
        for(int i = 2; i <= numRows; i++){
            vector<int> now;
            for(int j = 0; j < i; j++){
                if(j == 0 || j == i - 1){
                    now.emplace_back(1);
                }
                else{
                    now.emplace_back(ans.back()[j - 1] + ans.back()[j]);
                }
            }
            ans.emplace_back(now);
        }
        return ans;
    }
};