class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int idx_l = 0, idx_r = n - 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                ans[idx_l++] = nums[i];
            }
            if(nums[n - 1 - i] > pivot){
                ans[idx_r--] = nums[n - 1 - i];
            }
        }
        while(idx_l <= idx_r){
            ans[idx_l++] = pivot;
        }
        return ans;
    }
};