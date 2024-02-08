class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return max(ans, cnt);
    }
};