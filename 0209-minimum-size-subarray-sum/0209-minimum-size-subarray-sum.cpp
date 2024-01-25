class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        nums.emplace_back(0);
        int curr = nums[0];
        int curr_len = 1;
        int min_len = INT_MAX;
        int start_idx = 0;
        for(int i = 1; i < nums.size(); i++){
            while(curr >= target){
                min_len = min(min_len, curr_len);
                curr -= nums[start_idx++];
                curr_len--;
            }
            curr += nums[i];
            curr_len++;
        }
        cout << start_idx << '\n';
        return min_len == INT_MAX ? 0: min_len;
    }
};