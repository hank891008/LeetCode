class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans(n * m);
        int x = 0, y = 0, now = 0;
        int i = 0;
        while(i < n * m){
            ans[i] = matrix[x][y];
            if(i == n * m - 1){
                break;
            }
            int new_x = x + dir[now][0], new_y = y + dir[now][1];
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && matrix[new_x][new_y] != INT_MIN){
                matrix[x][y] = INT_MIN;
                x = new_x;
                y = new_y;
                i++;
            }
            else{
                now = (now + 1) % 4;
            }
        }
        return ans;
    }
};