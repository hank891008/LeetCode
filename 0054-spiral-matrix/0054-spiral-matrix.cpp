class Solution {
public:
    int dir[4][2] = {0, 1,1, 0,0, -1,-1, 0};
    bool valid(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = -1;
        int now = 0;
        int cnt = 0;
        bool used[n][m];
        memset(used, 0, sizeof(used));
        while(now < n * m){
            int now_i = i + dir[cnt][0], now_j = j + dir[cnt][1];
            if(valid(now_i, now_j, n, m) && !used[now_i][now_j]){
                ans.emplace_back(matrix[now_i][now_j]);
                used[now_i][now_j] = true;
                i = now_i;
                j = now_j;
                now++;
            }
            else{
                cnt = (cnt + 1) % 4;
            }
        }
        return ans;
    }
};