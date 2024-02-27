class Solution {
public:
    int pos[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int n, m;
    vector<vector<char>> b;
    string w;
    bool check(int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }
    bool dfs(int i, int j, int idx){
        if(w[idx] != b[i][j]){
            return false;
        }
        else if(idx == w.size() - 1){
            return true;
        }
        bool ans = false;
        char tmp = b[i][j];
        b[i][j] = '#';
        for(auto [x, y]: pos){
            int next_i = i + x, next_j = j + y;
            if(check(next_i, next_j)){
                ans |= dfs(next_i, next_j, idx + 1);
            }
        }
        b[i][j] = tmp;
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        b = board;
        w = word;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i, j, 0)){
                    return true;
                }
            }
        }
        return false;
        
    }
};