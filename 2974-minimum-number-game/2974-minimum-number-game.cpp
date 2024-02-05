class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num: nums){
            pq.emplace(num);
        }
        nums.clear();
        while(!pq.empty()){
            int a = pq.top();   pq.pop();
            int b = pq.top();   pq.pop();
            nums.emplace_back(b);
            nums.emplace_back(a);
        }
        return nums;
    }
};