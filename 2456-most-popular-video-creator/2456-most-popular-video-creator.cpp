class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();

        unordered_map<string, pair<int, long long>> total_views;

        for(int i = 0; i < n; i++) {
            if(!total_views.count(creators[i])) {
                total_views[creators[i]] = {i, views[i]};
            }
            else {
                int prev_idx = total_views[creators[i]].first;
                if(views[prev_idx] < views[i] || (views[prev_idx] == views[i] && ids[prev_idx] > ids[i])) {
                    total_views[creators[i]].first = i;
                }
                total_views[creators[i]].second += views[i];
            }
        }
        long long maxx = 0;
        vector<vector<string>> ans;
        for(auto [creator, p]: total_views) {
            auto [i, tot] = p;
            if(tot > maxx) {
                maxx = tot;
                ans.clear();
            }
            if(tot == maxx) {
                ans.push_back({creator, ids[i]});
            }
        }
        return ans;
    }
};