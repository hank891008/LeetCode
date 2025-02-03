class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> m;
        for(auto p: adjacentPairs){
            m[p[0]].emplace_back(p[1]);
            m[p[1]].emplace_back(p[0]);
        }
        int start;
        for(auto [x, y]: m){
            if(y.size() == 1){
                start = x;
                break;
            }
        }
        unordered_set<int> used;
        vector<int> ans;
        while(!used.count(start)){
            ans.emplace_back(start);
            used.insert(start);
            if(m[start].size() == 2){
                if(!used.count(m[start][0])){
                    start = m[start][0];
                }
                else{
                    start = m[start][1];
                }
            }
            else{
                start = m[start][0];
            }
        }

        return ans;
    }
};