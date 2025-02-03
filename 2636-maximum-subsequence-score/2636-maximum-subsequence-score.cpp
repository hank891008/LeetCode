class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        pair<int, int> p[n];
        for(int i = 0; i < n; i++){
            p[i] = {nums2[i], nums1[i]};
        }
        sort(p, p + n);
        reverse(p, p + n);
        long long now = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            now += p[i].second;
            pq.emplace(p[i].second);
        }
        long long ans = now * p[k - 1].first;
        for(int i = k; i < n; i++){
            now += p[i].second;
            pq.emplace(p[i].second);
            now -= pq.top();
            pq.pop();
            ans = max(ans, now * p[i].first);

        }
        return ans;
    }
};