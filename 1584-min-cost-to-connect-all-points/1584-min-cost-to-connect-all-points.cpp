class Solution {
public:
    struct Edge{
        int x, y, w;
        bool operator<(const Edge& rhs)const{
            return w < rhs.w;
        }
    };
    int fa[1005];
    int findr(int x){
        return x == fa[x] ? fa[x]: x = findr(fa[x]);
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i = 0; i < points.size(); i++){
            fa[i] = i;
        }
        vector<Edge>v;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back({i, j, dis});
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0, cnt = 0; i < v.size(); i++){
            if(cnt == (int)points.size() - 1){
                break;
            }
            
            if(unite(v[i].x, v[i].y)){
                ans += v[i].w;
                cnt++;
            }
        }
        return ans;
    }
};