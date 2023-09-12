class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n, 0);
        stack<pair<int, int>>s;
        s.emplace(temperatures[0], 0);
        for(int i = 1; i < n; i++){
            while(!s.empty() && s.top().first < temperatures[i]){
                auto now = s.top(); s.pop();
                ans[now.second] = i - now.second;
            }
            s.emplace(temperatures[i], i);
        }
        return ans;
    }
};