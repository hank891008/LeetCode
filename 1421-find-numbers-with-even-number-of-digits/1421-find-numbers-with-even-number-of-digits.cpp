class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto& num: nums){
            ans += to_string(num).size() % 2 == 0;
        }
        return ans;
    }
};