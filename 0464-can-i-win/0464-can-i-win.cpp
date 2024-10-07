class Solution {
public:
    unordered_map<int, char> state;
    bool search(int m, int t, int now){
        if(t <= 0){
            return false;
        }
        if(state.count(now)){
            return state[now];
        }
        for(int i = 0; i < m; i++){
            if(now & (1 << i)){
                continue;
            }
            if(!search(m, t - (i + 1), now | (1 << i))){
                return state[now] = 1;
            }
        }
        state[now] = 0;
        return false;
    }
    bool canIWin(int M, int T) {
        if(M * (M + 1) / 2 < T){
            return false;
        }
        if(T == 0){
            return true;
        }
        return search(M, T, 0);
    }
};