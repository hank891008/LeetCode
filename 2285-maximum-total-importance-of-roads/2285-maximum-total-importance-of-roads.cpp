class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> city(n);
        for(auto road: roads){
            city[road[0]]++;
            city[road[1]]++;
        }
        sort(city.begin(), city.end());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (i + 1) * city[i];
        }
        return ans;
    }
};