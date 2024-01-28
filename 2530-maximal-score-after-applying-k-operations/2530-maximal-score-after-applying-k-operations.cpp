class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto num: nums){
            pq.emplace(num);
        }
        long long ans = 0;
        for(int i = 0; i < k; i++){
            int now = pq.top(); pq.pop();
            cout << now << ' ';
            ans += now;
            pq.emplace(ceil(now / 3.));
        }
        return ans;
    }
};