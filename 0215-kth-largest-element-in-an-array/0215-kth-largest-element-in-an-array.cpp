class Solution {
public:
    int solve(vector<int>& nums, int k){
        int p = nums[(int)nums.size() - 1];
        vector<int>l, m, r;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > p){
                l.emplace_back(nums[i]);
            }
            else if(nums[i] == p){
                m.emplace_back(nums[i]);
            }
            else{
                r.emplace_back(nums[i]);
            }
        }
        if(k <= l.size()){
            return solve(l, k);
        }
        if(l.size() + m.size() < k){
            return solve(r, k - l.size() - m.size());
        }
        return p;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};