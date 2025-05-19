class Solution {
public:
    vector<int> fa, sz;
    void init(int n){
        fa.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int findr(int x){
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }
    void unite(int x, int y){
        x = findr(x);
        y = findr(y);
        if(x == y){
            return;
        }
        if(sz[x] >= sz[y]){
            fa[y] = x;
            sz[x] += sz[y];
        }
        else{
            fa[x] = y;
            sz[y] += sz[x];
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        init(n);
        for(auto& edge: edges){
            unite(edge[0], edge[1]);
        }
        unordered_map<int, int> edge_cnt;
        for(auto& edge: edges){
            edge_cnt[findr(edge[0])]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == findr(i) && edge_cnt[i] == sz[i] * (sz[i] - 1) / 2){
                ans++;
            }
        }
        return ans;
    }
};