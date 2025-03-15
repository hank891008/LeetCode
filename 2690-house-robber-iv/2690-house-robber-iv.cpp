class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int m = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= m){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= k){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};