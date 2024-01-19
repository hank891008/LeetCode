class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1){
            return matrix[0][0];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int prev_min = INT_MAX;
                for(int k = max(0, j - 1); k <= min(n - 1, j + 1); k++){
                    prev_min = min(prev_min, matrix[i - 1][k]);
                }
                matrix[i][j] += prev_min;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};