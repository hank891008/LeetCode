class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        string ans;
        for(auto num: nums){
            ans += to_string(num);
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};