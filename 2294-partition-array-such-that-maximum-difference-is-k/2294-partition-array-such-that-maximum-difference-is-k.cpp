class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int gp = 1;
        int minn = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if((nums[i] - minn) > k){
                gp++;
                minn = nums[i];
            }
        }
        return gp;
    }
};