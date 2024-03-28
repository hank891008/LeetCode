class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int, int> m;
        while(l < nums.size() && r < nums.size()){
            if(!m.count(nums[r]) || m[nums[r]] < k){
                m[nums[r]]++;
                ans = max(ans, r - l + 1);
                r++;
            }
            else{
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            // cout << l << ' ' << r << '\n';
        }
        ans = max(ans, r - l);
        return ans;
    }
};