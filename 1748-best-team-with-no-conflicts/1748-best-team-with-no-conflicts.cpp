class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> p(n);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            p[i] = {ages[i], scores[i]};
        }
        sort(p.begin(), p.end());
        for(int i = 0; i < n; i++){
            ans[i] = p[i].second;
            for(int j = 0; j < i; j++){
                if(p[i].second >= p[j].second){
                    ans[i] = max(ans[i], ans[j] + p[i].second);
                }
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};