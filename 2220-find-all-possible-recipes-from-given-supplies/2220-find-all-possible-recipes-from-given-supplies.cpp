class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        queue<string> q(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> G;
        unordered_map<string, int> in_deg;
        for(int i = 0; i < recipes.size(); i++){
            for(auto ingred: ingredients[i]){
                G[ingred].emplace_back(recipes[i]);
                in_deg[recipes[i]]++;
            }
        }
        vector<string> ans;
        while(!q.empty()){
            string u = q.front(); q.pop();
            for(auto v: G[u]){
                in_deg[v]--;
                if(in_deg[v] == 0){
                    q.emplace(v);
                    ans.emplace_back(v);
                }
            }
        }
        return ans;
    }
};