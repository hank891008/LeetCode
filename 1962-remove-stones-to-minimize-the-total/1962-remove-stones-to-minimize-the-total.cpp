class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto p: piles){
            pq.emplace(p);
        }
        for(int i = 0; i < k; i++){
            int now = pq.top(); pq.pop();
            pq.emplace(now - floor(now / 2));
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();    pq.pop();
        }
        return ans;
    }
};