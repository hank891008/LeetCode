class Solution {
public:
    int halveArray(vector<int>& nums) {
        double tot = 0;
        for(auto num: nums){
            tot += num;
        }
        priority_queue<double> pq(nums.begin(), nums.end());
        double k = 0;
        int cnt = 0;
        while(2 * k < tot){
            auto now = pq.top(); pq.pop();
            k += now / 2;
            pq.emplace(now / 2);
            cnt++;
        }
        return cnt;
    }
};