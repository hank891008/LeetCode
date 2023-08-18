class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    bool check(int n, int m, int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        if(image[sr][sc] == color){
            return image;
        }
        queue<pair<int, int>>q;
        int old_color = image[sr][sc];
        q.emplace(sr, sc);
        while(!q.empty()){
            auto now = q.front();   q.pop();
            image[now.first][now.second] = color;
            for(int i = 0; i < 4; i++){
                int x = now.first + dir[i][0];
                int y = now.second + dir[i][1];
                if(check(n, m, x, y) && image[x][y] == old_color){
                    q.emplace(x, y);
                }
            }
        }
        return image;
    }
};