class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>used(deadends.begin(), deadends.end());
        if(used.count("0000")){
            return -1;
        }
        queue<string>q;
        string now = "0000";
        q.emplace(now);
        used.insert(now);
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                now = q.front();   q.pop();
                if(now == target){
                    return step;
                }
                for(int i = 0; i < 4; i++){
                    char tmp = now[i];
                    int up = tmp - '0' + 1;
                    if(up == 10){
                        up = 0;
                    }
                    now[i] = '0' + up;
                    if(!used.count(now)){
                        used.insert(now);
                        q.emplace(now);
                    }
                    int down = tmp - '0' - 1;
                    if(down == -1){
                        down = 9;
                    }
                    now[i] = '0' + down;
                    if(!used.count(now)){
                        used.insert(now);
                        q.emplace(now);
                    }
                    now[i] = tmp;
                }
            }
            step++;
        }
        return -1;
    }
};