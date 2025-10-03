using LL = long long int;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> left_distance(n), right_distance(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left_distance[i] = s.empty() ? i + 1: i - s.top();
            s.emplace(i); 
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right_distance[i] = s.empty() ? n - i : s.top() - i;
            s.emplace(i);
        }
        LL ans = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            ans = (ans + (LL)arr[i] * (LL)left_distance[i] * (LL)right_distance[i] % MOD) % MOD;
        }
        return (int)ans;
        
    }
};