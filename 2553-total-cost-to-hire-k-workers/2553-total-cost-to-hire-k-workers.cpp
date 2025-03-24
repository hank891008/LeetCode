class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int i = 0, j = costs.size() - 1;
        long long ans = 0;
        while(k--){
            while(pq1.size() < candidates && i <= j){
                pq1.emplace(costs[i++]);
            }
            while(pq2.size() < candidates && j >= i){
                pq2.emplace(costs[j--]);
            }
            int ans1 = !pq1.empty() ? pq1.top() : INT_MAX;
            int ans2 = !pq2.empty() ? pq2.top() : INT_MAX;
            if(ans1 <= ans2){
                ans += ans1;
                pq1.pop();
            }
            else{
                ans += ans2;
                pq2.pop();
            }
        }
        return ans;
    }
};