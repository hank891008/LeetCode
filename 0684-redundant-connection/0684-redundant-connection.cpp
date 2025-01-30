class Solution {
public:
    const static int MAXN = 1000 + 5;
    int fa[MAXN];
    void init(){
        for(int i = 0; i < MAXN; i++){
            fa[i] = i;
        }
    }
    int findr(int x){
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }
    bool unite(int x, int y){
        x = findr(x);
        y = findr(y);
        if(x == y){
            return false;
        }
        fa[x] = y;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(auto edge: edges){
            if(!unite(edge[0], edge[1])){
                return edge;
            }
        }
        return {};
    }
};