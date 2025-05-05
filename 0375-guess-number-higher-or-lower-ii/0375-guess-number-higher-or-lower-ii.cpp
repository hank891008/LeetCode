class Solution {
public:
    map<pair<int, int>, int> used;
    int dfs(int s, int e){
        if(s >= e){
            return 0;
        }
        if(s + 1 == e){
            return s;
        }
        if(!used[{s, e}]){
            int minn = INT_MAX;
            for(int i = s + 1; i < e; i++){
                minn = min(minn, i + max(dfs(s, i - 1), dfs(i + 1, e)));
            }
            used[{s, e}] = minn;
        }
        return used[{s, e}];
    }

    int getMoneyAmount(int n) {
        return dfs(1, n);
    }
};