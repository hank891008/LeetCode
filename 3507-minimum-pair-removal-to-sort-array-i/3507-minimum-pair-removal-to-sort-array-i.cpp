class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(nums.size() > 1) {
            int maxx = INT_MAX;
            int idx = -1;
            bool flag = true;
            for(int i = 0; i < nums.size() - 1; i++) {
                int curr = nums[i] + nums[i + 1];
                if(nums[i] > nums[i + 1]) {
                    flag = false;
                }
                if(curr < maxx) {
                    maxx = curr;
                    idx = i;
                }
            }
            if(flag) {
                break;
            }
            nums[idx] = maxx;
            nums.erase(nums.begin() + idx + 1);
            cnt++;
        }
        return cnt;
    }
};