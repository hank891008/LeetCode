class Solution {
public:
    int dir[4][2] = {0, 1,
                     1, 0,
                     0, -1,
                     -1, 0};
    bool valid(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int i = 0, j = -1;
        int cnt = 0;
        int now = 0;
        while(now < n * n){
            if(valid(i + dir[cnt][0], j + dir[cnt][1], n) && v[i + dir[cnt][0]][j + dir[cnt][1]] == 0){
                v[i += dir[cnt][0]][j += dir[cnt][1]] = ++now;
            }
            else{
                cnt = (cnt + 1) % 4;
            }
        }
        return v;
    }
};