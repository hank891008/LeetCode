class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minn = 0;
        int tot = 0;
        for(auto num: nums){
            tot += num;
            minn = min(minn, tot);
        }
        return 1 - minn;
    }
};