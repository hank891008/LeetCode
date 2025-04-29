class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxx = *max_element(nums.begin(), nums.end());
        vector<int> maxx_idx;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxx){
                maxx_idx.emplace_back(i);
            }
            int cnt = maxx_idx.size();
            if(cnt >= k){
                ans += maxx_idx[cnt - k] + 1;
            }
        }
        return ans;
    }
};