class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> G(n);
        set<int> s;
        for(int i = 0; i < rooms.size(); i++){
            for(auto room: rooms[i]){
                G[i].emplace_back(room);
            }
        }
        queue<int> q;
        q.emplace(0);
        while(!q.empty()){
            int u = q.front();    q.pop();
            s.insert(u);
            for(auto v: G[u]){
                if(!s.count(v)){
                    q.emplace(v);
                }
            }
        }
        return s.size() == n;
    }
};