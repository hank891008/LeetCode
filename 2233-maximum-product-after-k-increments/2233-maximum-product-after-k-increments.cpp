class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto num: nums){
            pq.emplace(num);
        }
        while(k > 0){
            int now = pq.top(); pq.pop();
            int cmp = pq.top();
            if(cmp - now < k && cmp != now){
                pq.emplace(cmp % MOD);
                k -= (cmp - now);
            }
            else if(cmp == now){
                pq.emplace((now + 1) % MOD);
                k--;
            }
            else{
                pq.emplace((now + k) % MOD);
                k = 0;
            }
        }
        int ans = 1;
        while(!pq.empty()){
            ans = (ans * (long long)pq.top()) % MOD;
            pq.pop();
        }
        return ans;
    }
};