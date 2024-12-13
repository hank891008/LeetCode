class Solution {
public:
    struct Item{
        int val;
        int idx;
        Item(int val, int idx):val(val), idx(idx){}
        bool operator<(const Item& rhs) const{
            return val > rhs.val || (val == rhs.val && idx > rhs.idx);
        }
    };
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<Item> pq;
        for(int i = 0; i < n; i++){
            pq.emplace(Item(nums[i], i));
        }
        
        vector<bool> used(n, 0);
        long long ans = 0;
        while(!pq.empty()){
            auto now = pq.top();    pq.pop();
            if(!used[now.idx]){
                ans += now.val;
                for(int i = max(0, now.idx - 1); i <= min(n - 1, now.idx + 1); i++){
                    used[i] = true;
                }
            }
        }
        return ans;
    }
};