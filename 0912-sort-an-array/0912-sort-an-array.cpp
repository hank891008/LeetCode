class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r){
        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1;
        for(int idx = 0; idx < tmp.size(); idx++){
            if(i > m){
                tmp[idx] = nums[j++];
            }
            else if(j > r){
                tmp[idx] = nums[i++];
            }
            else if(nums[i] >= nums[j]){
                tmp[idx] = nums[j++];
            }
            else{
                tmp[idx] = nums[i++];
            }
        }
        for(int idx = 0; idx < tmp.size(); idx++){
            nums[l + idx] = tmp[idx];
        }
    }
    void merge_sort(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        int m = (l + r) / 2;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};