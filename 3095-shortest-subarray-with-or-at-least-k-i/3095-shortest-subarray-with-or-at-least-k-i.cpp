class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minn = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int arr = 0;
            for(int j = i; j < nums.size(); j++){
                arr |= nums[j];
                if(arr >= k){
                    minn = min(minn, j - i + 1);
                    break;
                }
            }
        }
        return minn == INT_MAX ? -1 : minn;
    }
};