class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(int l, int r, vector<int>& cuts){
        if(l + 1 == r){
            return 0;
        }
        if(mp[{l, r}]){
            return mp[{l, r}];
        }
        int ans = INT_MAX;
        for(int i = l + 1; i < r; i++){
            ans = min(ans, solve(l, i, cuts) + solve(i, r, cuts) + cuts[r] - cuts[l]);
        }
        return mp[{l, r}] = ans;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(0, cuts.size() - 1, cuts);
    }
};