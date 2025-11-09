class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int used[105] = {0};
        int ans1 = -1, ans2 = -1;
        for(auto num: nums) {
            if(used[num]) {
                if(ans1 == -1) {
                    ans1 = num;
                } else {
                    ans2 = num;
                }
            }
            used[num]++;
        }
        return {ans1, ans2};
    }
};