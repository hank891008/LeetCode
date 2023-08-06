class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] > b[1] || (a[1] == b[1] && a[0] > b[0]);
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filter;
        for(auto it: restaurants){
            if((it[2] == 1 || veganFriendly == 0) && it[3] <= maxPrice && it[4] <= maxDistance){
                filter.emplace_back(it);
            }
        }
        sort(filter.begin(), filter.end(), cmp);
        vector<int>ans;
        for(auto it: filter){
            ans.emplace_back(it[0]);
        }
        return ans;
    }
};