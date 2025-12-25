class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int> pq(happiness.begin(), happiness.end());
        for(int i = 0; i < k; i++) {
            ans += max((pq.top() - i), 0);
            pq.pop();
        }
        return ans;
    }
};