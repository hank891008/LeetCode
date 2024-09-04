class Robot {
public:
    int curr = 0, dir = 0, cnt;
    int w, h;
    int pos[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<pair<int, int>> v;
    vector<int> p;
    bool check(int _x, int _y){
        return _x >= 0 & _x < w && _y >= 0 & _y < h;
    }
    Robot(int width, int height) {
        w = width;
        h = height;
        cnt = (w + h) * 2 - 4;
        v.resize(cnt + 5);
        p.resize(cnt + 5);
        v[0] = {0, 0};
        p[0] = dir;
        for(int i = 1; i <= cnt; i++){
            auto now = v[i - 1];
            while(!check(now.first + pos[dir][0], now.second + pos[dir][1])){
                dir = (dir + 1) % 4;
            }
            p[i] = dir;
            v[i] = {now.first + pos[dir][0], now.second + pos[dir][1]};
        }
    }
    
    void step(int num) {
        curr += num;
        while(curr > cnt){
            curr -= cnt; 
        }
    }
    
    vector<int> getPos() {
        return {v[curr].first, v[curr].second};
    }
    
    string getDir() {
        if(p[curr] == 0){
            return "East";
        }
        else if(p[curr] == 1){
            return "North";
        }
        else if(p[curr] == 2){
            return "West";
        }
        else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */