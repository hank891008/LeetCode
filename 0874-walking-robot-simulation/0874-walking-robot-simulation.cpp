class Solution {
public:
    // 0 n, 1 e, 2 s, 3 w
    int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxn;
    set<pair<int, int>> obst;
    void walk(pair<int, int>& now, int dir, int units){
        for(int i = 0; i < units; i++){
            if(!obst.count({now.first + pos[dir][0], now.second + pos[dir][1]})){
                now = {now.first + pos[dir][0], now.second + pos[dir][1]};
            }
        }
        maxn = max(maxn, now.first * now.first + now.second * now.second);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto obstacle: obstacles){
            obst.insert({obstacle[0], obstacle[1]});
        }
        int dir = 0;
        pair<int, int> now = {0, 0};
        for(auto cmd: commands){
            if(cmd < 0){
                if(cmd == -1){
                    dir = (dir + 1) % 4;
                }
                else{
                    dir = (dir + 3) % 4;
                }
            }
            else{
                walk(now, dir, cmd);
            }
        }
        return maxn;
        
    }
};