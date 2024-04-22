class Solution {
public:
    const static int MAXN = 2e5 + 5;
    int fa[MAXN];
    int rank[MAXN];
    void init(int n){
        for(int i = 0; i < n; i++){
            fa[i] = i;
            rank[i] = 1;
        }
    }
    int findr(int x){
        return x == fa[x] ? x : fa[x] = findr(fa[x]);
    }
    void unite(int x, int y){
        x = findr(x);
        y = findr(y);
        if(x == y){
            return;
        }
        if(rank[x] >= rank[y]){
            fa[y] = x;
            rank[x] += rank[y];
        }
        else{
            fa[x] = y;
            rank[y] += rank[x];
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init(n);
        for(auto edge: edges){
            unite(edge[0], edge[1]);
        }
        return findr(source) == findr(destination);
    }
};