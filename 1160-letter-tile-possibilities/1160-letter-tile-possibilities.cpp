class Solution {
public:
    unordered_set<string> s;
    vector<int> used;
    void dfs(string now, string tiles){
        if(now.size()){
            s.insert(now);
        }
        for(int i = 0; i < tiles.size(); i++){
            if(!used[i]){
                used[i] = true;
                now += tiles[i];
                dfs(now, tiles);
                used[i] = false;
                now.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        used.resize(tiles.size());
        dfs("", tiles);
        return s.size();
    }
};