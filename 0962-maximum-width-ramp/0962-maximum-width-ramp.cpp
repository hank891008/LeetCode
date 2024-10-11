class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++){
            idx[i] = i;
        }
        stable_sort(idx.begin(), idx.end(), [&](int i, int j){
           return nums[i] < nums[j]; 
        });
        int max_width = 0, min_idx = n;
        for(int i = 0; i < n; i++){
            max_width = max(max_width, idx[i] - min_idx);
            min_idx = min(min_idx, idx[i]);
        }
        return max_width;
    }
};