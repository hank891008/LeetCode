class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, r = 0;
        int zero = 0;
        int cnt = 0;
        while(l < nums.size() && r < nums.size()){
            if(nums[r] == 1){
                cnt++;
                r++;
            }
            else if(nums[r] == 0 && zero < k){
                zero++;
                cnt++;
                r++;
            }
            else{
                if(nums[l] == 0){
                    zero--;
                }
                cnt--;
                l++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};