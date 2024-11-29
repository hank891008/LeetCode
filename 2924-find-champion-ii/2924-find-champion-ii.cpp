class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(i);
        }
        for(int i = 0; i < edges.size(); i++){
            if(s.count(edges[i][1])){
                s.erase(edges[i][1]);
            }
        }
        if(s.size() == 1){
            return *s.begin();
        }
        else{
            return -1;
        }
    }
};