class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        for(auto &comps: favoriteCompanies){
            sort(comps.begin(), comps.end());
        }
        vector<int> ans;
        for(int i = 0; i < favoriteCompanies.size(); i++){
            bool flag = true;;
            for(int j = 0; j < favoriteCompanies.size(); j++){
                if(i == j){
                    continue;
                }
                flag = !includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(), favoriteCompanies[i].begin(), favoriteCompanies[i].end());
                if(!flag){
                    break;
                }
            }
            if(flag){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};