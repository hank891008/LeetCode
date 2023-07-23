class Solution {
public:
    string alphabetBoardPath(string target) {
        string board[6][5];
        map<char, pair<int, int>>m;
        int x = 0, y = 0;
        for(int i = 0; i < 26; i++){
            board[x][y] = 'a' + i;
            m['a' + i] = {x, y};
            y++;
            if(y == 5){
                x++;
                y = 0;
            }
        }
        x = 0, y = 0;
        string ans;
        for(int i = 0; i < target.size(); i++){
            int t_x = m[target[i]].first, t_y = m[target[i]].second;
            while(x != t_x || y != t_y){
                if(x < t_x){
                    ans += 'D';
                    x++;
                    if(x == 5 && y > 0){
                        ans.pop_back();
                        x--;
                    }
                }
                if(x > t_x){
                    ans += 'U';
                    x--;
                }
                if(y < t_y){
                    ans += 'R';
                    y++;
                    if(x == 5 && y > 0){
                        ans.pop_back();
                        y--;
                    }
                }
                if(y > t_y){
                    ans += 'L';
                    y--;
                }
            }
            ans += '!';
        }
        return ans;
    }
};