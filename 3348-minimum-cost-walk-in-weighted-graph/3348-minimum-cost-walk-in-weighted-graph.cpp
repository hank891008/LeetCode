class Solution {
public:
    vector<int> fa, min_weight;
    void init(int n){
        min_weight.assign(n, 0xffffffff);
        fa.resize(n);
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    }
    int findr(int x){
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }
    void unite(int x, int y){
        x = findr(x);
        y = findr(y);
        fa[x] = y;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        init(n);
        for(auto& edge: edges){
            unite(edge[0], edge[1]);
        }
        for(auto& edge: edges){
            int root = findr(edge[0]);
            min_weight[root] &= edge[2];
        }
        vector<int> ans;
        for(auto& q: query){

            if(findr(q[0]) != findr(q[1])){
                ans.emplace_back(-1);
            }
            else{
                ans.emplace_back(min_weight[findr(q[0])]);
            }
        }
        return ans;
    }
};