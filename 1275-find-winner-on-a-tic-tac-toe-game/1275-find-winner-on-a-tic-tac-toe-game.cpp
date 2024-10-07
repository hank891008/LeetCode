class Solution {
public:
    int win_x[8][3] = {
        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 2},
        {0, 1, 2},
        {0, 1, 2},
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 0}
    };
    int win_y[8][3] = {
        {0, 1, 2},
        {0, 1, 2},
        {0, 1, 2},
        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 2},
        {0, 1, 2},
        {0, 1, 2}
    };
    string tictactoe(vector<vector<int>>& moves) {
        char board[3][3];
        memset(board, -1, sizeof(board));
        bool flag = true;
        for(auto m: moves){
            board[m[0]][m[1]] = flag;
            flag ^= 1;
        }

        for(int i = 0; i < 8; i++){
            int x0 = win_x[i][0], x1 = win_x[i][1], x2 = win_x[i][2];
            int y0 = win_y[i][0], y1 = win_y[i][1], y2 = win_y[i][2];
            if(board[x0][y0] != -1 && board[x0][y0] == board[x1][y1] && board[x1][y1] == board[x2][y2]){
                return board[x0][y0] == 1 ? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};